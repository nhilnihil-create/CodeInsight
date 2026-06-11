#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll N ;
    ll D;
    cin >> N >> D ;

    ll X[N];
    ll F[N];

    ll res = 0;
    ll idx = 0;
    ll count = 0;

    for (ll i = 0 ; i <N;i++)
    {
      cin >> X[i] >> F[i];
      if (X[i]*X[i]+F[i]*F[i] <= D*D)
      count++;
    }

    cout << count;

    return 0;
}
