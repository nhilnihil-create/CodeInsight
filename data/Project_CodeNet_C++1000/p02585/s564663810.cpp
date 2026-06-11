#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll N, K;
    cin >> N >> K;
    vector<ll> P(N), C(N);
    for(int i=0;i<N;i++){
        cin >> P[i];
        P[i]--;
    }
    for(int i=0;i<N;i++){
        cin >> C[i];
    }

    vector<bool> used(N, false);
    vector<vector<ll>> groups;
    for(int i=0; i<N; i++){
        if(used[i]) continue;

        vector<ll> group;
        int j = i;
        while(true){
            used[j] = true;
            group.push_back(C[j]);
            j = P[j];
            if(i == j) break;
        }
        groups.push_back(group);
    }

    ll res = numeric_limits<ll>::min();
    for(auto group : groups){
        vector<ll> vsum = {0};
        for(auto v : group){
            vsum.push_back(v + vsum.back());
        }
        ll ngroup = group.size();
        auto nloop = K / ngroup;
        ll val;
        for(int i=0; i<ngroup; i++){
            for(int j=0; j<min(K, ngroup); j++){
                if(i+j+1 >= ngroup){
                    val = vsum[i+j+1-ngroup] - vsum[i] + vsum.back();
                }else{
                    val = vsum[i+j+1] - vsum[i];
                }
                res = max(res, val);

                if(nloop > 0){
                    res = max(res, val + (nloop - 1) * vsum.back());
                }

                if(j < K%ngroup){
                    res = max(res, val + nloop * vsum.back());
                }
            }
        }
    }
    cout << res << endl;

    return 0;
}
