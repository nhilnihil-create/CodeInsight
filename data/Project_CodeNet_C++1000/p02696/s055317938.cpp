#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
ll A, B, N;
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   cin >> A >> B >> N;
   ll x = min(N, B - 1);
   cout << floor(A * x / B) - A * floor(x / B) << endl;

   return 0;
}
