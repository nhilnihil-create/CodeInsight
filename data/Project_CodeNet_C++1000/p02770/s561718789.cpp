#include<bits/stdc++.h>
using namespace std;
/*int n,m=INT_MAX,x=INT_MIN;
int A[100];
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        m = min(m, A[i]);
        x = max(x, A[i]);
    }
    long long ans = INT_MAX;
    for (int i = m; i < x+1; i++)
    {
        long long k = 0;
        for (int j = 0; j < n; j++)
        {
            k += (A[j] - i) * (A[j] - i);
        }
        ans = min(ans, k);
        //cout << ans << " ";
    }
    cout << ans;
}*/ 
#define ll long long
/*long long a, b, c;
//int fac[200001];

long long power(long long x, long long y, long long p)
{
    if (x == 1 and y != 0) return 1;
    long long res = 1;      // Initialize result 

    long long k = x % p;  // Update x if it is more than or 
                // equal to p 
    //cout << "(" << k << "," << y << "," << p << ")=";
    while (y > 0)
    {
        // If y is odd, multiply x with result 
        if (y & 1)
            res = (res * k) % p;
        //cout << y << ":" << res<<","<<k << " ";
        // y must be even now 
        y = y >> 1; // y = y/2  
        k = (k * k) % p;
    }
    //cout << res<<" ";
    return res;
}

long long modInverse(long long n, long long p)
{
    return power(n, p - 2, p);
}

long long nCrModP(long long n, long long r, long long p)
{
    // Base case 
    if (r == 0)
        return 1;
    long long z=1,y=1;
    for (long long i = n; i > n - r; i--)
        z = (z * i) % p;
    for (int i = 2; i <= r; i++)
        y = (y * i) % p;
    long long k= (z * modInverse(y, p))%p;
    //cout << "(" << n << "," << r << ")=" << k;
    return k;
}
int main()
{
    //fac[0] = 1;
    cin >> c >> a >> b;
    int ans = power(2, c, 1000000007)-1;
    //cout << ans << " ";
    ans -= (nCrModP(c, a, 1000000007) + nCrModP(c, b, 1000000007)) % 1000000007;
    //cout << nCrModP(c, a, 1000000007)<<"->";
    //cout << nCrModP(c, b, 1000000007);
    if (ans >= 0)
        cout << ans;
    else cout << ans + 1000000007;
}*/
/*const int M = 1000000007,N=400000+1;
ll fac[N];
long long power(long long j, int k)
{
    //cout << "power of" << j << ":\n";
    if (j == 1 and k != 0) return 1;
    long long res = 1;
    j = j % M;
    while (k)
    {
        //cout << k << "->";
        if (k & 1)
            res = (res * j) % M;
        k = k >> 1;
        j = j * j%M;
       // cout << res << "," << j << " ";
    }
   // cout << "\n";
    return res;
}
long long nCr(int a, int b)
{
    if (b == 0)
        return 1;
    //cout << fac[a] << " " << power(fac[b], M - 2) << " " << power(fac[a - b], M - 2) << ":\n";
    return fac[a] * (power(fac[b], M - 2) * power(fac[a - b], M - 2) % M) % M;
}
int main()
{
    fac[0] = 1;
    int n, k;
    cin >> n >> k;
    for (int i = 1; i < N; i++)
    {
        fac[i] = fac[i - 1] * i % M;
    }
    ll ans = nCr(2*n-1,n-1);
    for (++k; k < n; k++)
    {
        ans = (ans + M - nCr(n, k) * nCr(n - 1, n - k - 1)%M)%M;
    }
    cout << ans;
}*/
// Problem F: common sense 
int k, q;
int Ar[50001];
int main()
{
    cin >> k >> q;
    for (int i = 0; i < k; i++)
    {
        cin >> Ar[i];
        //Ar[i + 1] += Ar[i];
    }
    while (q--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        ll s1 = 0, s2 = 0;
        for (int i = 0; i < k; i++)
        {
            ll d = Ar[i] % c; // only remainder part affect result in increasing next term from m so focus on that only
            if (d == 0)
                d = c; // when this happens (ai mod m) = (ai+1 mod m), this also doesn't satisfy our answer
            s1 += d;
            if (i < (a - 1) % k)
                s2 += d; // this sum is only used once whereas s1 appears in every cycle
        }
        ll l = b + ((a - 1) / k) * s1 + s2; // cycles of s1
        cout << a - 1 - (l / c - b / c) << "\n";
    }
}

    