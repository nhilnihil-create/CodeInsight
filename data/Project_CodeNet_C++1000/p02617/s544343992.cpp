#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  long long N; cin >> N;

  long long ALL = 0, OUT = 0;
  rep1(i, N) {
    ALL += i * (N - i + 1);
  }

  rep(i, N - 1) {
    int u, v; cin >> u >> v;
    if (u > v) swap(u, v);
    OUT += u * (N - v + 1);
  }

  cout << ALL - OUT << endl;
}
