#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;

    long long ans = 0;
    long long k;
    for( k = 2; k * k < n; k++ )
    {
        if( (n - 1) % k == 0 ) 
        {
            if( (n - 1) / k == k )
            {
                ans += 1;
            }
            else
            {
                ans += 2;            
            }            
        }
        if( n % k == 0 )
        {
            long long a = n / k;
            while( a % k == 0 ) a /= k;
            if( a % k == 1 ) ans++;
        }
    }
    if( k * k == n ) ans++;
    ans += 1;
    if( n >= 3) ans += 1;

    cout << ans;
}