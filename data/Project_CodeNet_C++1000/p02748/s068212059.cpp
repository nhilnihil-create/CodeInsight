// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define rep(i,n) for (int i = 0; i < n; ++i)
#define repr(i,n) for (int i = n; i > 0; --i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int MAX = 100;
const int INF = (1<<12);

int main() {
  int a, b, M;
  cin >> a >> b >> M;
  vector<int> A(a), B(b), cA(a), cB(b);
  rep(i,a) cin >> A[i];
  rep(i,b) cin >> B[i]; 
  cA = A;
  cB = B;

  sort(cA.begin(), cA.end());
  sort(cB.begin(), cB.end());
  int cost = cA[0] + cB[0];

  rep(i,M){
    int x,y,c;
    cin >> x >> y >> c;
    cost = min(cost, A[x-1] + B[y-1] - c);
  }
  cout << cost << endl;
  return 0;
}