#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep_inv(i, n, m) for(int i = (int)(n); i > (int)(m); i--)
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vc = vector<char>;
using vvl = vector<vl>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

int main(){
  vvl A(3, vl(3));
  rep(i, 3){
    rep(j, 3) cin >> A[i][j];
  }
  ll N;
  cin >> N;
  vl b(N);
  rep(i, N) cin >> b[i];

  vvl hit(3, vl(3, 0));

  rep(t, N){
    rep(i, 3){
      rep(j, 3){
	if(b[t] == A[i][j]) hit[i][j] = 1;
      }
    }
  }

  rep(i, 3){
    if((hit[i][0] == 1) && (hit[i][1] == 1) && (hit[i][2] == 1)){
      cout << "Yes\n";
      return 0;
    }
  }

  rep(j, 3){
    if((hit[0][j] == 1) && (hit[1][j] == 1) && (hit[2][j] == 1)){
      cout << "Yes\n";
      return 0;
    }
  }

  if((hit[0][0] == 1) && (hit[1][1] == 1) && (hit[2][2] == 1)){
    cout << "Yes\n";
    return 0;
  }

  if((hit[0][2] == 1) && (hit[1][1] == 1) && (hit[2][0] == 1)){
    cout << "Yes\n";
    return 0;
  }

  cout << "No\n";
  
  return 0;
}
