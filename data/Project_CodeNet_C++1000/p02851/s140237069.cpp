#include <bits/stdc++.h>
using namespace std;
#define int long long

int N,K;
vector<int> A;
vector<int> c;

signed main()
{
  cin >> N >> K;
  A.resize(N);
  c.resize(N+1);

  for(int i=0; i<N; i++) cin >> A[i];
  for(int i=0; i<N; i++) c[i+1] = (c[i] + A[i] - 1) % K;

  int count=0;
  unordered_map<int, int> m;
  m[0]=1;
  for(int i=1; i<=N; i++)
  {
    if( i - K >= 0 ) m[c[i-K]]--;
    count += m[c[i]];
    m[c[i]]++;
  }
  cout << count << endl;
}
