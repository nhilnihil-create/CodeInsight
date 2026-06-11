#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (int)(n);i++)
using ll = long long;
const ll MOD=1000000007;
const long long INF = 1LL << 60;
const double pi=acos(-1.0);

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll N;

//dfs
vector<string> vec;

void dfs(ll n,ll cha,string str){
  if(n==N-1){vec.push_back(str); return;}
  rep(i,cha+1){
    auto sstr=str;
    sstr+=char(i+'a');
    dfs(n+1,cha,sstr);
  }
  str+=char(cha+1+'a');
  dfs(n+1,cha+1,str);
}
int main()
{
  cin>>N;
  
  //dfs
  vec=vector<string>(0);
  dfs(0,0,"a");
  
  sort(vec.begin(),vec.end());
  
  for(auto str:vec) cout<<str<<endl;
  
  return 0;
}