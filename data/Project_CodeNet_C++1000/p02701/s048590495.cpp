#include <bits/stdc++.h>

typedef long long LL;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

template<typename Container>
bool include(const Container& c, const typename Container::value_type& v) {
  return ( c.end() != std::find(c.begin(),c.end(),v) );
}

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string> S(N);
  int cnt = 0;
  rep(i, N)
    cin >> S[i];

  std::sort(S.begin(), S.end());
  S.erase(std::unique(S.begin(), S.end()), S.end());

  cout << S.size() << endl;

  return 0;
}
