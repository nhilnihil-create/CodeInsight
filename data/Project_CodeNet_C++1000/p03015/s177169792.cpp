//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main() {
    string l; cin>>l;
    ll n=l.size();
    vector<ll> r(n,0),u(n,0);
    r[0]=2; u[0]=1;
    for(ll i=1;i<n;i++){
        if(l[i]=='1'){
            r[i]=(2*r[i-1])%MOD;
            u[i]=(r[i-1]+3*u[i-1])%MOD;
        }
        else{
            r[i]=r[i-1]%MOD;
            u[i]=3*u[i-1]%MOD;
        }
    }
    cout<<(r[n-1]+u[n-1])%MOD<<endl;
}