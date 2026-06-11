#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;
const long long INF = 1LL << 60;
const double pi=acos(-1);

string S;

//dp
vector<ll> table;

ll dp(ll n){
  //cout<<"d"<<" "<<n<<endl;
  if(S.at(n)=='R'&&S.at(n+1)=='L') return n;
  if(S.at(n)=='L'&&S.at(n-1)=='R') return n;
  if(table.at(n)>-1) return table.at(n);
  
  if(S.at(n)=='R'){
    if(S.at(dp(n+1))=='R') table.at(n)=dp(n+1)+1;
    else table.at(n)=dp(n+1)-1;
  }
  else{
    if(S.at(dp(n-1))=='R') table.at(n)=dp(n-1)+1;
    else table.at(n)=dp(n-1)-1;
  }
  
  return table.at(n);
}


  
int main() 
{
  cin>>S;
  ll N=S.size();
  
  //dp
  table=vector<ll>(N,-1);

  /*
  rep(i,N){
    if(i!=0) cout<<" ";
    cout<<dp(i);
  }
  */
  vector<ll> vec(N,0);
  rep(i,N) vec.at(dp(i))++;
  
  rep(i,N){
    if(i!=0) cout<<" ";
    cout<<vec.at(i);
  }
  cout<<endl;

  return 0;
}