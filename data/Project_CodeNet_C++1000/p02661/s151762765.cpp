#include <bits/stdc++.h>
typedef long long int ll;



using namespace std;

int main()
{

  int N;

  cin >> N;

  vector<ll> A(N);
  vector<ll> B(N);

  for (int i = 0; i < N; i++)
  {

    ll a, b;
    cin >> a >> b;

    A[i]=a;
    B[i]=b;
  }

  sort(A.begin(), A.end());
  sort(B.begin(), B.end());


  ll kasu =0;

  if (N % 2 == 0)
  {
    kasu = 1+2*((double)(B[N / 2 - 1] + B[N / 2])/2. - (double)(A[N / 2 - 1] + A[N / 2])/2.);
  }
  else
  {
    kasu = B[(N + 1) / 2 - 1] - A[(N + 1) / 2 - 1] + 1;
  }

  cout << kasu << endl;
  return 0;
}
