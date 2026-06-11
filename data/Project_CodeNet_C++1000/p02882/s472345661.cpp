#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,a,n) for(ll i = a;i < n;i++)
#define rrep(i,a,n) for(ll i = n; i >= a;i--)
#define index_check(i,n) if(i > n-1 || i < 0) continue; 
#define LINF 1e18
#define INF 1e9
using namespace std;

#define fs first
#define sc second

using P = pair<ll,ll>;
using PQ = priority_queue<P,vector<P>,greater<P>>;

signed main(){
    double a,b,x;
    cin >> a >> b >> x;
    
    if(2*x/a >= a*b) cout << setprecision(15) << atan(2*b/a-2*x/a/a/a)*180/acos(-1) << endl;
    else cout << setprecision(15) << atan(a*b*b/2/x)*180/acos(-1) << endl;

    return 0;
}