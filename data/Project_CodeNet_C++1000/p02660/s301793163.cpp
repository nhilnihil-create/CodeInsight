#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,ll>
const ll MOD=998244353;
const int INF=1e9;
const double PI=acos(-1);


map<ll,int> prime_factor(ll n) {
    map<ll,int> res;
    repr(i,2,sqrt(n)+1) {
        while (n%i==0) {
            ++res[i];
            n/=i;
        }
    }
    if(n!=1) ++res[n];
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);

    ll n;
    cin >> n; 
    map<ll,int> pf=prime_factor(n);
    ll ans=0;
    repitr(itr,pf) {
        int k=itr->second;
        double sk=sqrt(1+1.0*8*k)-1;
        double tans=sk/2;
        ans+=int(tans);
    }
    cout << ans << endl;

}
