//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (long long i = 0; i < (long long)n; i++)
//
using namespace std;
using ll = long long;
using Pi = pair<int, int>;
using Pl = pair<ll, ll>;
using Vl = vector<ll>;
using vi = vector<int>;
using Graph = vector<vi>;
const ll MOD = 1000000007;

int main(){
  int A,B;
  cin >> A >> B;
  cout << max(0,A-2*B) << endl;
  
}