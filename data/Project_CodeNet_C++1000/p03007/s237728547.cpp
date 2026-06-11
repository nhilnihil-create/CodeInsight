#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll N;
    cin >> N;
    vector<pair<ll,ll>> a(N);
    rep(i, 0, N){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    ll neg = a[0].first;
    ll pos = a[N-1].first;
    vector<ll> ans;
    rep(i, 1, N-1){
        if(a[i].first < 0){
            ans.push_back(pos);
            pos -= a[i].first;
        }else{
            ans.push_back(neg);
            neg -= a[i].first;
        }
    }
    cout << pos - neg << endl;
    rep(i, 1, N-1){
        cout << ans[i-1] << " " << a[i].first << endl;
    }
    cout << pos << " " << neg << endl;
    return 0;
}