#include <bits/stdc++.h>

#define REPI(x) for(int i=0;i<x;i++)
#define REPJ(x) for(int j=0;j<x;j++)

#define REPISE (s,e) for(int i=s,i<e;i++)
#define REPJSE (s,e) for(int j=s,j<e;j++)

typedef long long ll;

using namespace std;

int main ()
{
  int N,b,res=0;
  vector<int> B;  
  cin >> N;

  REPI(N-1)
  {
    cin >> b;
    B.push_back (b);
  }

  res += B[0];
  res += B[N-2];

  REPI(N-2)
    res += min(B[i],B[i+1]);

  cout << res << endl;

  return 0;
}