#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;
typedef long long ll;

int A[200001];
map<int, int> D;

int main(){
  int N;
  cin >> N;
  rep(i, N-1) cin >> A[i];
  rep(i, N-1){
    if (D.count(A[i])) D[A[i]]++;
    else D[A[i]] = 1;
  }
  rep(i, N) cout << D[i+1] << endl;
}
