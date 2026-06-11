#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repab(i, a, b) for (int i = a; i <= (int)(b); i++)
#define ll long long
#define vec vector
#define pb push_back
#define ft first
#define sd second
#define all(vec) vec.begin(), vec.end()
#define endl "\n"

typedef pair<int, int> P;

const int MOD = 1e9 + 7;
const int INF = 1001001001;
const int dx[4] = {1, 0,-1, 0};
const int dy[4] = {0, 1, 0,-1};

//--//--//--//--//--//--//--//--//--//--//--//

const int A = 1000005;

int main(){
  int n;
  cin >> n;
  vec<int> a(n);
  vec<int> c(A);
  rep(i, n){
    cin >> a[i];
    c[a[i]]++;
  }

  bool pairwise = true;
  for(int i = 2; i < A; i++){
    int cnt = 0;
    for(int j = i; j < A; j += i){
      cnt += c[j];
    }
    if(cnt > 1){
      pairwise = false;
    }
  }

  if(pairwise){
    cout << "pairwise coprime" << endl;
    return 0;
  }

  int g = 0;
  rep(i, n){
    g = gcd(g, a[i]);
    if(g == 1){
      cout << "setwise coprime" << endl;
      return 0;
    }
  }

  cout << "not coprime" << endl;
  
  return 0;
}