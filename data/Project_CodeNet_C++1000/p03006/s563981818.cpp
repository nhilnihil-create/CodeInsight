#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

long long MOD = 1000000000 + 7;
long long MAX = 1000000000000000000;

int main(){
  cout << setprecision(10);

  int N;
  cin >> N;
  vector<pll> v(N);
  for(int i = 0; i < N; i++){
    ll x,y;
    cin >> x >> y;
    v.at(i) = make_pair(x,y);
  }

  map<pll,int > m;
  for(int i = 0; i < N-1; i++){
    for(int j = i+1; j < N; j++){
      pll p1,p2;
      p1 = v[i];
      p2 = v[j];

      ll diff_x = p1.first - p2.first;
      ll diff_y = p1.second - p2.second;

      m[make_pair(diff_x, diff_y)]++;
      m[make_pair(-diff_x, -diff_y)]++;
    }
  }

  int max_val = 0;
  for(auto x: m){
    max_val = max(max_val, x.second);
  }
  cout << N - max_val << endl;
}
