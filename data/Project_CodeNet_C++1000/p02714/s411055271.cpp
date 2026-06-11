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
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> r(n+1);
  vector<int> g(n+1);
  vector<int> b(n+1);
  for(int i=n-1; i>=0; i--){
    r[i]=r[i+1];
    g[i]=g[i+1];
    b[i]=b[i+1];
    if(s[i]=='R'){
      r[i]++;
    } else if(s[i]=='G'){
      g[i]++;
    } else {
      b[i]++;
    }
  }
  ll ans=0;
  rep(i, n){
    for(int j=i+1; j<n; j++){
      if((s[i]=='R'&&s[j]=='G')||(s[i]=='G'&&s[j]=='R')){
        ans+=b[j+1];
        if(2*j-i<n && s[2*j-i]=='B'){
          ans--;
        }
      } else if((s[i]=='G'&&s[j]=='B')||(s[i]=='B'&&s[j]=='G')){
        ans+=r[j+1];
        if(2*j-i<n && s[2*j-i]=='R'){
          ans--;
        }
      } else if((s[i]=='B'&&s[j]=='R')||(s[i]=='R'&&s[j]=='B')){
        ans+=g[j+1];
        if(2*j-i<n && s[2*j-i]=='G'){
          ans--;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
