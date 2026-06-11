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
ll S;
  cin>>S;
ll x,y;
  x=1;
  y=S;
  if(S>NINE){
  if(S%NINE==0){
  ll t=S/NINE;
  t--;
    x=x+t;
    y=S-t*NINE;
  }
  else{
  ll t=S/NINE;
    x=x+t;
    y=S-t*NINE;
  }
  }
  cout<<0<<' '<<NINE<<' '<<1<<' '<<0<<' '<<x<<' '<<y;
}