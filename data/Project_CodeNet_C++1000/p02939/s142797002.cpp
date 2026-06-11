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
  ll n=a.size();
  ll ans=1;
  string b,g;
 b=a[0];
  g="";
  for(ll i=1;i<n;i++){
g=g+a[i];
  if(b!=g){
  ans++;
  b=g;
   g="";
  }
   
    
  }
  
  cout<<ans;
  
  
  
  
}