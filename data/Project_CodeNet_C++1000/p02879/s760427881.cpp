#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
#define fi(i, n) for( int i=0 ; i<n ; i++ )
#define fir(i, n) for( int i=n-1; i>=0 ; i-- )
#define fj(j, n) for( int j=0 ; j<n ; j++ )
#define fjr(j, n) for( int j=n-1; j>=0 ; j-- )
#define f(i, a, b) for( int i=a ; i<b ; i++ )
#define vi vector<int>
#define pb push_back
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);

}

int main()
{
    ll a,b;
    cin>>a>>b;
    if(a>9 || b>9)
    {
        cout<<"-1";
        return 0;
    }
    cout<<a*b;
}
