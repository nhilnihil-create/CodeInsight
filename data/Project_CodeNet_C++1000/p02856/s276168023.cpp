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
  ll t=0;
  ll s=-1;
  rep(i,n){
  ll a,b;
    cin>>a>>b;
   
  t=t+a*b;
    s=s+b;
  }
 s=s+t/9;
  if(t%9==0) s--;
  cout<<s;

}
