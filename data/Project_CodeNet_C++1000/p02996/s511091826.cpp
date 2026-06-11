#include <bits/stdc++.h>
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
typedef long long ll;
typedef pair<int, int> P;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<P> ba(N);
  FOR(i,0,N) {
    int a, b;
    cin >> a >> b;
    ba[i] = P(b, a);
  }
  sort(ba.begin(), ba.end());

  int now = 0;
  FOR(i,0,N) {
    int end = now + ba[i].second;
    if (end > ba[i].first) {
      cout << "No" << endl;
      exit(0);
    }
    now = end;
  }
  cout << "Yes" << endl;
}