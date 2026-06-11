#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef vector<vector<int>> Matrix;



int main(){
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int c = 0;
  rep(i, n-1) if (s[i] == s[i+1]) c++;
  int ans = min(c+2*k, n-1);
  cout << ans << endl;
}
