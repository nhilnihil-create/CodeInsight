#include <bits/stdc++.h>

using namespace std;

long long sum(long long l, long long r)
{
    return (l + r)*(r - l + 1) / 2;
}

int main(void)
{
    long long N, K;
    cin >> N >> K;

    // 10^100 : 10^9 + 7 is relatively prime
    // 10^ 9 + 7 is prime
    // 10 ^ 100 = (10 ^ 10) ^ 10
    // Fermet: a * b^n-1 mod n = a mod n
    // (a + b) mod n = (a mod n + b mod n) mod n
    // a*b mod n = ((a mod n ) *( b mod n )) mod n
    // (a mod n) mod n = a mod n
    // 10^ 100 = (10 mod n) ^ 100

   vector<int> v(N);
   for(int i = 0; i<N + 1;i++) {
       v[i] = i;
   }

   long long max = 0;
   long long min = 0;
   long long ans = 0;
   for (long long j = K;j <= N+1;j++) {
       min = sum(0,j-1);
       max = sum(N - j + 1,N);
       ans += (max - min + 1);
       ans = ans % 1000000007;
   }
   cout << ans << endl;
   return 0 ;
}