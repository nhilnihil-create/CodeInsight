#include <bits/stdc++.h>
#include <string>
using namespace std;

#define ll long long
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))

const int N =100;

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
bool ispalindrome(string s)
{
    int n = s.length();
    for(int i=0;i<n/2;i++)
    {
        if(s[i]!=s[n-i-1])
            return false;
    }
    return true;
}
bool isPerfectSquare(long double x)
{
  long double sr = sqrt(x);
  return ((sr - floor(sr)) == 0);

}
ll f(ll n) {
	return n * (n - 1) / 2;
}
bool cmp(const tuple<int, string, string>& a,
               const tuple<int, string, string>& b)
{
    return (get<0>(a) < get<0>(b));
}

void solve()
{
    long double w,h,x,y;
    cin>>w>>h>>x>>y;
    cout<<fixed<<setprecision(10)<<(w*h)/2<<" ";
    if(w==2*x && h==2*y)
        cout<<1<<endl;
    else
        cout<<0<<endl;
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
