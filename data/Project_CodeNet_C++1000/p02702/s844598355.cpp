#include<iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define P_B push_back
#define E_B emplace_back
#define fi first
#define se second

using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  string S;
  ll N, ans=0;

  cin >> S;
  N = S.size();

  vector<int> s(N);
  vector<vector<int> > A(2, vector<int> (2019, 0));
  vector<vector<int> > B(2019, vector<int> (10));

  rep(i, N){
    s[i] = S[i] - '0';
  }

  rep(i, 2019){
    rep(j, 10){
      B[i][j] = (i*10 + j) % 2019;
    }
  }

  //A[0].assign(2019, 0);
  A[0][s[0]] = 1;

  rep(i, N-1){
    A[1][s[i+1]] += 1; //'0'があれば if(s[i+1] != 0) が必要
    rep(j, 2019){
      A[1][B[j][s[i+1]]] += A[0][j];
    }
    rep(j,2019){
      A[0][j] = A[1][j];
      A[1][j] = 0;
    }
    ans += A[0][0];
  }

  cout << ans << endl;

  return 0;
}
