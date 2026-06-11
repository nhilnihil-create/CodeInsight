#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define f first
#define s second
#define fore(i,a,b) for(lli i = (a), ThxMK = (b); i < ThxMK; ++i)
#define pb push_back
#define all(s) begin(s), end(s)
#define rall(s) rbegin(s), rend(s)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(s) int(s.size())
#define ENDL '\n'
using namespace std;
typedef long double ld;
typedef long long lli;
typedef pair<lli,lli> ii;
typedef vector<lli> vi;
#define deb(x) cout << #x": " << (x) << endl;
int main(){ _
    lli n;
    cin >> n;
    vector<lli> v(0);
    fore(i,0,n)
    {
      lli o;
      cin >> o;
      v.pb(o);
      cin >> o;
      v.pb(o);
    }
    for(lli i=0; i<n*2-5; i+=2)
    {
      if(v[i]==v[i+1] && v[i+2]==v[i+3] && v[i+4]==v[i+5])
      {
        cout << "Yes" <<ENDL;
        return 0;
      }
    }
    cout << "No" <<ENDL;
    return 0;
}
