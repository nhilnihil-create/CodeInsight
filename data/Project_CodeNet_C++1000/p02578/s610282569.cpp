#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repc(i, a, b) for (int i = a; i <= (int)(b); i++)
#define ll long long
#define vec vector
#define pb push_back
#define ft first
#define sd second
#define all(vec) vec.begin(), vec.end()

typedef pair<int, int> P;

const int MOD = 1e9 + 7;
const int INF = 1001001001;
const int dx[4] = {1, 0,-1, 0};
const int dy[4] = {0, 1, 0,-1};

//------------------------------------------------------//

int main(){
  int n;
  cin >> n;
  vec<int> a(n);
  rep(i, n){
    cin >> a[i];
  }

  ll step = 0;
  rep(i, n-1){
    if(a[i] > a[i+1]){
      step += a[i] - a[i+1];
      a[i+1] += a[i] - a[i+1];
    }
  }
  cout << step << endl;
  return 0;
}