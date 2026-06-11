#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
const long long INF = 1ll << 60;



int main() {
  int N; cin >> N;
  string S; cin >> S;
  int c = 0;
  rep(i,N-2){
    if(S.substr(i,3) == "ABC")c++;
  }
  cout << c << endl;

	return 0;
}

