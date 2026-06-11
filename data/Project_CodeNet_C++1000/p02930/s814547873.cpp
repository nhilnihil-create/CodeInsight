#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
using namespace std;
typedef pair<ll,ll> pll;

ll n;
ll a[505][505];
void solve(vector<ll> v, ll lvl)
{
        if(v.size() <= 1) return;
        vector<ll> A;
        vector<ll> B;
        for(ll i=0;i<v.size();i++){
                if(i%2 == 0) A.pb(v[i]);
                else B.pb(v[i]);
        }
        solve(A,lvl+1);
        solve(B,lvl+1);
        for(auto &i : A) {
                for(auto &j : B) {
                        a[i][j] = lvl;
                        a[j][i] = lvl;
                }
        }
}
int main()
{
        cin >> n;
        vector< ll > v;
        for(ll i=1;i<=n;i++) {
                v.pb(i);
        }
        solve(v, 1);
        for(ll i=1;i<=n;i++) {
                for(ll j=i+1;j<=n;j++) {
                        cout << a[i][j] << " ";
                }
                cout << "\n";
        }
        return 0;
}
