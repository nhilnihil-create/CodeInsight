#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;
typedef long long ll;

int A[200001];
int ANS[200001];

int main(){
  int N;
  cin >> N;
  rep(i, N-1) cin >> A[i];
  rep(i, N-1) ANS[A[i]]++;
  rep(i, N) cout << ANS[i+1] << endl;
}
