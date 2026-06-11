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
   string s;
   int c=0;
   cin>>s;
   for(int i=1;i<s.length();i++)
   {
       if(s[i]==s[i-1])
       {
           c++;
           break;
       }
   }
   if(!c)
    cout<<"Good"<<endl;
   else
    cout<<"Bad"<<endl;
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
