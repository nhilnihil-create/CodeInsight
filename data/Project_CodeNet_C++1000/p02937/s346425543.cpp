#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
    string s, t;
    cin >> s >> t;

    ll ans = -1;
    vector<vector<int>> a(26);
    rep(i, s.size()){
        a[s[i] - 'a'].pb(i);
    }

    rep (i, t.size()){
        if (a[t[i] - 'a'].empty()){
            cout << ans << endl;
            return 0;
        }
    }
    ll now = a[t[0] - 'a'][0];
    int res = 0;
    rep(i, t.size() - 1){
        auto it = upper_bound(a[t[i + 1] - 'a'].begin(), a[t[i + 1] - 'a'].end(), now);
        if (it - a[t[i + 1] - 'a'].begin() == a[t[i + 1] - 'a'].size()){
            now = a[t[i + 1] - 'a'][0];
            res++;
        }else{
            now = *it;
        }
    }
    ans = (ll)res * s.size() + now + 1;
    cout << ans << endl;
}