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
  string s;
  cin >> s;
  int q;
  cin >> q;
  int rev=0;
  string pre;
  string next;
  rep(i, q){
    int t;
    cin >> t;
    if(t==1){
      rev++;
    } else {
      int f;
      string c;
      cin >> f >> c;
      if((f==1 && rev%2==0) ||(f==2 && rev%2==1)){
        pre=c+pre;
      } else {
        next=next+c;
      }
    }
  }
  s=pre+s+next;
  if(rev%2==1){
    reverse(s.begin(), s.end());
  }
  cout << s << endl;
  return 0;
}
