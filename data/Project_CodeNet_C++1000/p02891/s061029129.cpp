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
 const int NINE=1000000000;
 
 
int main(){
string a;
  cin>>a;
  ll k;
  cin>>k;
  ll a1=0;
  ll n=a.size();
  ll t=1;
  rep(i,n-1){
  if(a[i]==a[i+1]) t++;
  else {
  a1=a1+t/2;
    t=1;
  
  }
  }
  a1=a1+t/2;
  ll a2=0;
  t=1;
  string c=a+a;
    rep(i,2*n-1){
  if(c[i]==c[i+1]) t++;
  else {
  a2=a2+t/2;
    t=1;
  
  }
  }
  a2=a2+t/2;
    ll a3=0;
  t=1;
  string d=a+a+a;
    rep(i,3*n-1){
  if(d[i]==d[i+1]) t++;
  else {
  a3=a3+t/2;
    t=1;
  
  }
  }
  a3=a3+t/2;
  if(t==3*n) cout<<n*k/2;
  else{
  if(k==1) cout<<a1;
  else if(k==2) cout<<a2;
  else if(k==3) cout<<a3;
  else cout<<a2+(a3-a2)*(k-2);
  }
}