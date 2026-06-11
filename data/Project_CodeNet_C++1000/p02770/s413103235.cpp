#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define pb push_back

typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<ld> vd;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

ll K,Q;
vll d;

void solve(){
    ll n,x,m;
    cin>>n>>x>>m;
    x%=m;
    ll zero=0;
    ll sum=x;
    F0R(i,K){
        ll val=d[i]%m;
        ll timer=(n-1)/K;
        if((n-1)%K>i){
            timer++;
        }
        if(val==0){
            zero+=timer;
        }else{
            sum+=(timer*val);
        }
    }
    ll out=(sum/m)-(x/m);
    cout<<(n-1)-(out+zero)<<endl;
}



int main(){
    
    cin>>K>>Q;
    d.resize(K);
    F0R(i,K){
        cin>>d[i];
    }
    while(Q--){
        solve();
    }
    return 0;
}
