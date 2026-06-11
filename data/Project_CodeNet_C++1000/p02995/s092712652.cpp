#include <bits/stdc++.h>

using namespace std;

#define ll long long

bool isprime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i*i<=n; i++)
        if (n % i == 0)
            return false;

    return true;
}
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}
long long lcm(long long a,long long b)
{
    long long p,r;
    p = a*b;
    r = __gcd(a, b);
    return p/r;
}
void solve()
{
   long long a,b,c,d,e,f,g,ans;
   cin>>a>>b>>c>>d;
   e = (b/c)-((a-1)/c);
   f = (b/d)-((a-1)/d);
   long long p = lcm(c,d);
   g = (b/p)-((a-1)/p);
   ans = b-a+1-e-f+g;
   cout<<ans<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
}
