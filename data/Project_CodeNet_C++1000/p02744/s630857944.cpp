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
#define SIZE(a) ll((a).size())
#define out(a) cout<<(a)<<endl;
const int inf=INT_MAX;
const int MAX = 510000;
const ll MOD = 1000000007;

int main(){
  ll n;cin>>n;
  string s="aaaaaaaaaa";
  set<string> ans;
  rep(a1,0,2){
    
    rep(a2,0,a1+2){
      ll m1=max(a1,a2);
      
      rep(a3,0,m1+2){
        ll m2=max(m1,a3);
        
        rep(a4,0,m2+2){
          ll m3=max(m2,a4);
          
          rep(a5,0,m3+2){
            ll m4=max(m3,a5);
            
            rep(a6,0,m4+2){
              ll m5=max(m4,a6);
              
              rep(a7,0,m5+2){
                ll m6=max(m5,a7);
                
                rep(a8,0,m6+2){
                  ll m7=max(m6,a8);
                  
                  rep(a9,0,m7+2){
                    string tmp=s;
                    tmp[1]+=a1;tmp[2]+=a2;tmp[3]+=a3;
                    tmp[4]+=a4;tmp[5]+=a5;tmp[6]+=a6;
                    tmp[7]+=a7;tmp[8]+=a8;tmp[9]+=a9;
                    ans.insert(tmp.substr(0,n));
                  }
                }
              }
            }

          }
        }
      }
    }
  }
  for(auto u:ans){
    cout<<u<<endl;
  }

}


