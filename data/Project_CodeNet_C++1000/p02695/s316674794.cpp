#include "bits/stdc++.h"
#include "math.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
typedef pair<ll,ll> P;
typedef vector<P> vp;
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define drep(i,a,b) for(ll i=(a);i>=(b);--i)
#define SIZE(a) int((a).size())
#define out(a) cout<<(a)<<endl;
const int inf=INT_MAX;
const int MAX = 510000;
const ll MOD = 1000000007;

int main(){
  ll n,m,q;cin>>n>>m>>q;
  vll a(q),b(q),c(q),d(q),A(10);
  rep(i,0,q){
    cin>>a[i]>>b[i]>>c[i]>>d[i];
    a[i]--;b[i]--;
  }
  ll ans=0;
  rep(i,1,m+1){
    A[0]=i;
    rep(j,i,m+1){
      A[1]=j;
      rep(k,j,m+1){
        A[2]=k;
        rep(l,k,m+1){
          A[3]=l;
          rep(x,l,m+1){
            A[4]=x;
            rep(y,x,m+1){
              A[5]=y;
              rep(z,y,m+1){
                A[6]=z;
                rep(w,z,m+1){
                  A[7]=w;
                  rep(u,w,m+1){
                    A[8]=u;
                    rep(v,u,m+1){
                      A[9]=v;
                      ll tmp=0;
                      rep(t,0,q){
                        if(A[b[t]]==(A[a[t]]+c[t])){
                          tmp+=d[t];
                        }
                      }
                      ans=max(ans,tmp);
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  cout<<ans<<endl;
}
