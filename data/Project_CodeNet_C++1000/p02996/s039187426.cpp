#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N;
  cin >> N;
  vector<P> w;
  for (int i = 0; i < N; i++)
  {
    int A, B;
    cin >> A >> B;
    w.push_back(make_pair(B, A));
  }
  sort(w.begin(), w.end());

  int now = 0;
  for (int i = 0; i < N; i++)
  {
    now += w[i].second;
    if (now > w[i].first)
    {
      cout << "No" <<endl;
      return 0;
    }
    
  }
  cout << "Yes" << endl;
  return 0;
}
