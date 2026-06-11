#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repo(i, n) for(int i=1; i<=n; i++)
#define INF 1001001001
#define INFll 100100100100100
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;

int main(){
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, h){
    cin >> s[i];
  }
  vector<vector<int> > up(h, vector<int>(w));
  vector<vector<int> > lr(h, vector<int>(w));
  rep(j, w){
    int num=0;
    rep(i, h){
      if(s[i][j]=='#'){
        num=0;
      } else {
        num++;
        up[i][j]=num;
      }
    }
    for(int i=h-1; i>=0; i--){
      if(s[i][j]=='.' && i!=h-1 && s[i+1][j]!='#'){
        up[i][j]=up[i+1][j];
      }
    }
  }
  rep(i, h){
    int num2=0;
    rep(j, w){
      if(s[i][j]=='#'){
        num2=0;
      } else {
        num2++;
        lr[i][j]=num2;
      }
    }
    for(int j=w-1; j>=0; j--){
      if(s[i][j]=='.' && j!=w-1 && s[i][j+1]!='#'){
        lr[i][j]=lr[i][j+1];
      }
    }
  }
  int ans=0;
  rep(i, h){
    rep(j, w){
      ans=max(ans, up[i][j]+lr[i][j]-1);
    }
  }
  cout <<ans << endl;
  return 0;
}
