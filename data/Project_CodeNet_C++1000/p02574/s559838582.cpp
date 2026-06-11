#include <bits/stdc++.h>
using namespace std;

using Int = long long;
const char newl = '\n';

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
template<typename T> void drop(const T &x){cout<<x<<endl;exit(0);}
template<typename T=int>
vector<T> read(size_t n){
  vector<T> ts(n);
  for(size_t i=0;i<n;i++) cin>>ts[i];
  return ts;
}

//INSERT ABOVE HERE
const int MAX = 2e6;
int dp[MAX]={};
int cnt[MAX]={};

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;
  auto as=read(n);
  int g=as[0];
  for(int a:as) g=gcd(g,a);
  if(g!=1) drop("not coprime");

  for(int i=2;i<MAX;i++){
    if(dp[i]) continue;
    for(int j=i;j<MAX;j+=i) dp[j]=i;
  }

  for(int a:as){
    int t=a;
    while(t!=1){
      int p=dp[t];
      while(t%p==0) t/=p;
      cnt[p]++;
    }
  }

  if(*max_element(cnt,cnt+MAX)>1) drop("setwise coprime");

  drop("pairwise coprime");
  return 0;
}
