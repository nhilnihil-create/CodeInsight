#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;



int main() {
    ll n; cin >> n;
    ll a,b,sum = 0;
    string ans = "Yes";
    vector<pair<ll,ll>> mp(n);
    rep(i,n){
        cin >> a >> b;
        mp[i] = make_pair(b,a);
    }
    sort(mp.begin(),mp.end());

    rep(i,n){

        sum += mp[i].second;
        if(sum > mp[i].first) {
            ans = "No";
            break;
        }


    }

    cout << ans;
    return 0;
}









