#include<bits/stdc++.h>
using namespace std;
    static const double pi = 3.141592653589793;
 typedef pair<int64_t,int64_t> P;
#define rep(i, n) for (int i = 0; i < (n); i++)
 #define all(v) (v).begin(),(v).end()
 using ll = long long;
using Graph = vector<vector<int>>;
const int MAX = 510000;
const int MOD = 1000000007;
 
 
 
int main(){
ll n;
  cin>>n;
  vector<ll>op(3);
  rep(i,3) op.at(i)=0;
  ll ans=1;
  rep(i,n){
  ll p;
    cin>>p;
  ll t=0;
    ll k=0;
    if(op.at(0)==p) {
      t=t+1;
    }
    if(op.at(1)==p){
    t=t+1;;
      k=1;
    }
    if(op.at(2)==p){
    t=t+1;
      k=2;
    }
    ans=ans*t%MOD;
    op.at(k)=op.at(k)+1;
  }
cout<<ans<<endl;
  
}
