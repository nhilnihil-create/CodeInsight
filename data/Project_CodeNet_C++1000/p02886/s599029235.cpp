#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)


int main()
{
  int N;
  cin >> N;
  vector<int> d(N);
  rep(i, N) cin >> d[i];
  int Sum = 0;

  rep(i,N){
    rep(j,N){
      if(i==j)
        continue;
      Sum += d[i] * d[j];
    }
  }
  cout << Sum/2 << endl;
  return 0;
}
