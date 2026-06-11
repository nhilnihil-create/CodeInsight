#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,start,end) for(int i=start;i<=end;i++)
const int INF = 1001001001;
using namespace std;
typedef long long ll;

int main()
{
  int N, M;
  cin >> N >> M;
  int sum = 0;
  vector<int> a(N);
  rep(i,N) {
    cin >> a[i];
    sum += a[i];
  }

  sort(a.begin(), a.end(), greater<int>());
  double th = (double)sum/(4*M);

  if ((double)a[M-1] < th ) cout << "No" << endl;
  else cout << "Yes" << endl;
}