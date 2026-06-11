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
        ll n,m,k,res=0;
        cin >> n >> m >> k;
        vll va(n+1) , vb(m+1);
        ll A=0, B=0;
        loop(i,1,n+1) { cin >> va[i]; va[i] = va[i]+va[i-1]; }
        loop(i,1,m+1) { cin >> vb[i]; vb[i] = vb[i]+vb[i-1]; }
        ll b = m , a = n;
        loop(i,1,n+1) if(va[i]<=k) a = i;
        loop(i,1,m+1) if(vb[i]<=k) b = i;
        loop(i,0,a+1){
            if(vb[b]+va[i] <= k) res = max(res,i+b);
            else b--;
            /*loop(j,0,b+1) {
                if (va[i] + vb[j] <= k) res = max(res,(ll)(i+j));
            }*/
        }
        cout << res;
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