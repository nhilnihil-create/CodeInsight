#include <bits/stdc++.h>
#define rep(i,e,n) for (int i = e; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;


int main(){
  int h,w;
  cin >> h >> w;
  vector<string> g(h);
  rep(i,0,h){
    string s;
    cin >> s;
    g[i]=s;
  }
//  cout << g[0] << endl;
  int ans=0;
  int r_count=0;
  int c_count=0;
  int k=0;
  vector<ll> c_memo(w);
  rep(i,0,h){
    rep(j,0,w){
      if(g[i][j]== '#') {
        r_count=0;
        c_memo[j]=0;
        continue;
      }
      if(r_count==0){
        k=1;
        while(j+k<w && g[i][j+k]=='.'){
          r_count++; k++;
        }
      }
      if(c_memo[j]==0){
        c_count=0;
        k=1;
        while(i+k<h && g[i+k][j]=='.'){
          c_count++; k++;
        } 
        c_memo[j]=c_count;
      }
      c_count=c_memo[j];
//      cout << r_count << ' ' << c_count << endl;
      ans = max(ans, r_count + c_count);
    }
    r_count=0;
  }
  cout << ans+1 << endl;
  return 0;
}
