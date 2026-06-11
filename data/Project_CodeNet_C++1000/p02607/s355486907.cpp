#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define SZ(c) int(c.size())
#define pb push_back
#define loop(i,start,n)  for(int i=start;i<n;i++)
#define rloop(i,start,n)  for(int i=start;i>n;i--)

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vs = vector<string>;
const ll inf = 2e9+3;

void solve(){
    int tc=1 ;
    //cin >> tc;
    while(tc--) {
        ll n, res = 0; cin >> n;
        loop(i,1,n+1){
            ll x;
            cin >> x ;
            if((i&1) && (x&1)) res++;
        }
        cout << res ;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}