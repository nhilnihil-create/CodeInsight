#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

typedef long long ll;
typedef vector<ll> vint;
typedef vector< vector<ll> > vvint;

#define rep(i,n) for(ll i=0;i<n;i++)
#define repf(i,f,n) for(ll i=f;i<n;i++)
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define mp make_pair
#define mt make_tuple
#define ALL(obj) (obj).begin(), (obj).end()
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int dy[]={0, 0, 1, -1, 1, -1, -1, 1};
int dx[]={1, -1, 0, 0, 1, 1, -1, -1};


int main() {
    cout<<fixed<<setprecision(10);

    int n,q; cin>>n>>q;
    dsu d(n);

    rep(_,q){
        int t,u,v;
        cin>>t>>u>>v;
        if(t==0){
            d.merge(u,v);
        }else{
            if(d.same(u,v)) cout<<1<<endl;
            else cout<<0<<endl;
        }
    }

    return 0;

}