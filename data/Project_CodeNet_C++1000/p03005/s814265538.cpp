/*
ID: skipian1
PROB: 
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF = 2000000000
#define sz(a) int((a).size())
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define X first
#define Y second

int main() {
  int n, k;
  cin  >> n >> k;
  if (k == 1) {
    cout << 0 << "\n";
  } else {
    cout << n-k << "\n";
  }
}
