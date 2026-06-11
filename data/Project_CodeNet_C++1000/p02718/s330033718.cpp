#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
const long long INF = 1ll << 60;



int main() {
  int N, M; cin >> N >> M;
  double A[N];
  int t = 0;
  rep(i,N){
    cin >> A[i];
    t+= A[i];
  }
  int c = 0;
  rep(i,N){
    if(A[i]*4*M>=t)c++;
  }

  if(c >= M)cout << "Yes" << endl;
  else cout << "No" << endl;


	return 0;
}

