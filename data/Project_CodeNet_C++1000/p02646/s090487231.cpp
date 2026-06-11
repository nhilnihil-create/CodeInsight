#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rep_ll(i,n) for(ll i = 0; i < (ll)(n); i++)
using namespace std;
typedef long long ll;
typedef unsigned long long u_ll;
typedef pair<int, int> pair_;
const long double PI = (acos(-1));
const int INF = 1001001001;
const int dx[] = {-1, 0, 1, 0}; const int dy[] = {0, -1, 0, 1};
ll mod = 1000000007;
int main(){
    ll a, b;
    ll v, w, t;
    cin >> a >> v;
    cin >> b >> w;
    cin >> t;
    int ans=0;
        //if(a==b) ans=1;
        ll dis=abs(a-b);
        ll bb= dis+t*w;
        ll aa= t*v;
        if(bb<=aa){
       ans=1;
      }
        if(ans) cout << "YES";
        else cout << "NO"; 
    //}
    return 0;
}