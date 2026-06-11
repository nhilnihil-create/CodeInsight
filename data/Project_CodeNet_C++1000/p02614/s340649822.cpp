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
  int h, w, k;
  cin >> h >> w >> k;
  vector<string> s(h);
  rep(i, h){
    cin >> s[i];
  }
  int ans=0;
  for (int bith = 0; bith < (1<<h); ++bith)
  {
    for (int bitw = 0; bitw < (1<<w); ++bitw){
      int sum=0;
      rep(i, h){
        rep(j, w){
          if((bith >> i) & 1==1 && (bitw >> j) & 1==1 && s[i][j]=='#'){
            sum++;
          }
        }
      }
      if(sum==k){
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
