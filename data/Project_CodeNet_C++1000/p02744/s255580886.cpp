#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<typename T> bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<typename T> bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef tuple<ll,ll,ll> tlll;
typedef tuple<int,int,int> tiii;
const ll mod=1e9+7;
const int inf=1<<30;

int n;
void dfs(string s,char mx){
  if(s.size()==n){
    cout << s << endl;
  }
  else{
    for(char c='a';c<=mx;c++){
      if(c==mx) dfs(s+c,mx+1);
      else dfs(s+c,mx);
    }
  }
}

int main(){
  cin >> n;
  dfs("a",'b');
  
}