#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repc(i, a, b) for (int i = a; i <= (int)(b); i++)
#define ll long long
#define vec vector
#define ft first
#define sd second
#define all(vec) vec.begin(), vec.end()
typedef pair<int, int> P;
const int MOD = 1e9 + 7;
const int INF = 1001001001;
const int dx[4] = {1, 0,-1, 0};
const int dy[4] = {0, 1, 0,-1};


int main(){
  int n;
  int x;
  cin >> n;
  x = n % 10;
  if(x == 3) cout << "bon" << endl;
  else if(x == 0 || x == 1 || x == 6 || x == 8) cout << "pon" << endl;
  else cout << "hon" << endl;
  return 0;
}