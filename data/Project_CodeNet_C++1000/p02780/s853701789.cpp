#include <bits/stdc++.h>
#include <iostream>
#include <ctime>
using namespace std;
#define _LL long long
#define rep(i, n) for (_LL i = 0; i < (_LL)(n); i++)
#define vecrep(itr, v) for (auto itr = (v).begin(); itr != (v).end(); itr++)

int main()
{
#if 1
   int n, k; cin >> n >> k;
   vector<int> p(n);
   rep(i, n) cin >> p[i];
#else
   int n = 200000;
   int k = 200000;
   vector<int> p(n);
   rep(i, n) p[i] = 1000;
#endif
   int sum = 0;
   rep(i, k) sum += p[i] + 1;
   int ans = sum;
   for( int i = k; i < n; i++ )
   {
       sum -= p[i - k];
       sum += p[i];
       ans = max(ans, sum);
   } 

   cout << ans / 2;
   if( ans % 2 == 1 ) cout << ".5";  
}