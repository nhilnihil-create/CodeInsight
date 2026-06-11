#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)
#define pai 3.14159265358979323846
const int INF = 1001001001;
typedef long long ll;
int A[3][3], N;
bool punched[3][3];
bool ok[3][3];
int a[3][3],n;
using Graph = vector<vector<int>>;
vector<vector<int>> field;
vector<bool> seen;



int main() {
  string s;
  cin >> s;
  bool ok = true;
  rep (i,s.size()){
      if(i%2==0){
          //cout << 0 << endl;
          if(s[i]!='R'&&s[i]!='U'&&s[i]!='D'){
            ok = false;
            break;
          }
      }
      if(i%2!=0){
          //cout << 1 << endl;
          if(s[i]!='L'&&s[i]!='U'&&s[i]!='D'){
            ok = false;
            break;
          }
      }

  }
  if(ok) cout << "Yes"  << endl;
  else cout << "No" << endl;

}

