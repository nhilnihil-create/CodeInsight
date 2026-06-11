#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ios::sync_with_stdio(false);
    ll N;
    cin >>N;
    vector<queue<ll>> vq(N);
    for(int i=0;i<N;i++)for(int j=0;j<N-1;j++){
        ll A;
        cin >> A;
        --A;
        vq[i].push(A);
    }

    ll remain = N*(N-1);
    ll ans =0;
    while(remain){
        vector<bool> skip(N,false);
        bool changed = false;
        for(int i=0;i<N;i++){
            if(skip[i]){
                continue;
            }
            if(!vq[i].empty()){

                ll t = vq[i].front();
                // cerr <<"i=" <<i <<" t = " << t << endl;
                if(vq[t].front() ==i && !skip[t]){
                    remain -=2;
                    changed = true;
                    skip[t] = true;
                    skip[i] = true;
                    vq[t].pop();
                    vq[i].pop();
                }
            }
        }
        if(!changed){
            cout <<-1 << endl;
            return 0;
        }

        ans++;
    }
    cout << ans << endl;



    return 0;
}