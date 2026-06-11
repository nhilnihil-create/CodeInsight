// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <numeric>
#include <cmath>

#define rep(i,n) for (int i = 0; i < n; ++i)
#define repr(i,n) for (int i = n; i > 0; --i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int MAX = 100;
const int INF = (1<<12);

int main() {
  ll N, A, B;
  cin >> N >> A >> B;
  if(A == 0){
    cout << 0 << endl;
    return 0;
  }
  ll sum = N / (A+B) * A;
  ll amari = N % (A+B);
  if(amari <= A) sum += amari;
  else sum += A;
  cout << sum << endl;
  return 0;
}