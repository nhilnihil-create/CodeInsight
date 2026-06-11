#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const ll INF=1e18;
const ll MOD=1e9+7;
const double pi=acos(-1);
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);  
  
  int n,a,b,c,d;
  cin >>n >> a >> b >> c >> d;
  string s;
  cin >> s;
  a--;
  b--;
  c--;
  d--;
  for(int i=a;i<c;i++){
    if(s[i]=='#' && s[i+1]=='#'){
      cout << "No"<< endl;
      return 0;
    }
  }
  for(int i=b;i<d;i++){
    if(s[i]=='#' && s[i+1]=='#'){
      cout << "No"<< endl;
      return 0;
    }
  }
  if(c<d){
    cout << "Yes" << endl;
    return 0;
  }
  else{
    for(int i=b;i<=d;i++){
      if(s[i-1]=='.' && s[i]=='.' && s[i+1]=='.'){
        cout << "Yes" << endl;
        return 0;
      }
    }
    cout << "No"<< endl;
    return 0;
  }
}