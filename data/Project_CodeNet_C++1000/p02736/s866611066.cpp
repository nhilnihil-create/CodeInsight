#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e6 + 9;

int vs[N];

int v2(int n, int k){
  return vs[n]-vs[k]-vs[n-k];
}

int solve(vector<int> t){
  int n = t.size();
  int r = 0;
  for(int i = 0 ; i < n; i ++ ){
    if(t[i] == 1){
      if(v2(n-1,i) == 0) r ^= 1;
    }
  }
  return r;
}

int main(){
  fastIO;
  vector<int> t;
  vector<int> mod;
  int n;
  cin >> n;
  int p;
  for(int i = 1 ; i <= n; i ++ ){
    p = i;
    while(p % 2 == 0){
      vs[i] ++ ;
      p /= 2;
    }
    vs[i] += vs[i - 1];
  }
  char y;
  int x;
  int has = 0;
  for(int i = 0 ; i < n;i  ++ ){
    cin >> y;
    x = y - '0';
    t.push_back(x-1);
    if(x == 2) has = 1;
    mod.push_back((x-1)%2);
  }
  int q = solve(mod);
  if(q == 1){
    cout << "1" << "\n";
  }
  else{
    if(has){
      cout << "0" << "\n";
    }
    else{
      for(auto &x : t){
        x /= 2;
      }
      if(solve(t)) cout << "2" << "\n";
      else cout << "0\n";
    }
  }
  return 0;
}