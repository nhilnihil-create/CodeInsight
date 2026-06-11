#include<bits/stdc++.h>

using namespace std;

int main()
{
  int N, X[100], Y[100];

  scanf("%d", &N);

  for(int i = 0; i < N; i++) scanf("%d", X + i);
  for(int i = 0; i < N; i++) scanf("%d", Y + i);

  int ret = 0;
  for(int i = 0; i < N; i++) ret = max(ret, abs(X[i] - Y[i]));

  auto get = [&](double p)
  {
    double res = 0;
    for(int i = 0; i < N; i++) {
      res += pow(abs(X[i] - Y[i]), p);
    }
    return (pow(res, 1.0 / p));
  };

  cout << fixed << setprecision(10);
  cout << get(1) << endl;
  cout << get(2) << endl;
  cout << get(3) << endl;
  cout << ret << endl;
}