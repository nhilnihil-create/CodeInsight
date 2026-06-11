#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,int>
const int MOD=998244353;
const int MAX=1e5+10;
const double PI=acos(-1);


int main() {
    ios_base::sync_with_stdio(false);

    ll a,b,v,w,t;
    cin >> a >> v >> b >> w >> t;
    ll d=abs(a-b);
    if (d<=(v-w)*t) cout << "YES" << endl;
    else cout << "NO" << endl;
     
    return 0;   
}