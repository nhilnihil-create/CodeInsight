#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long li;
#define rep(i,n) for(int i=0;i<(n);i++)
#define df 0
template<class T> void print(const T& t){ cout << t << "\n"; }
template<class T, class... Ts> void print(const T& t, const Ts&... ts) { cout << t; if (sizeof...(ts)) cout << " "; print(ts...); }
// Container コンテナ型, map以外
template< template<class ...> class Ctn,class T>
std::ostream& operator<<(std::ostream& os,const Ctn<T>& v){
  // ここでストリームに obj を書き込みます。
  auto itr=v.begin();
  while(itr!=v.end()){
    if(itr!=v.begin())cout << " ";
    cout << *(itr++);
  }
  return os;
}

int f(int a,int t,vector<int>& tim, vector<int>& del){
  vector<int> dp(t,0);
  int n=tim.size();
  rep(i,n){    // add del[i]
    if(i==a) continue;
    rep(j,t){
      int k=t-j-1;
      if(k<tim[i]) break;
      dp[k]=max(dp[k],dp[k-tim[i]]+del[i]);
    }
  }
  int ans=0;
  rep(i,t) if(ans<dp[i]) ans=dp[i];
  return ans;
}

int main(){
  int n,t; cin >>n >>t;
  vector<pair<int,int>> v(n);
  rep(i,n){
    int a,b; cin >>a >>b;
    v[i]={a,b};
  }
  sort(v.begin(),v.end());
  int ans=0;
  vector<int> dp(t,0);
  rep(i,n){    // add v[i]
    int m=0;
    rep(j,t) if(m<dp[j]) m=dp[j];
    m+=v[i].second;

    if(ans<m) ans=m;
    
    rep(j,t){
      int k=t-j-1;
      if(k<v[i].first) break;
      dp[k]=max(dp[k],dp[k-v[i].first]+v[i].second);
    }
    if(df)print(dp);
  }

  print(ans);
}
