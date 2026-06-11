#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  int N;
  cin >> N;
  // vector <string> S(N);
  // rep(i,N) cin >> S[i];
  set<string> st;
  rep(i,N){
    string S;
    cin >> S;
    st.insert(S);
  }
  cout << st.size() << endl;
  return 0;
}
