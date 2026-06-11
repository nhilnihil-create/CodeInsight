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
   int n,l,sum=0;
   cin>>n>>l;
   vector<int>temp;
   for(int i=1;i<=n;i++)
   {
       temp.push_back(l+i-1);
       sum += (l+i-1);
   }
   int d=10000;
   sort(temp.begin(),temp.end());
   for(int i=0;i<temp.size();i++)
   {
       if(temp[i]>=0)
       {
           d = temp[i];
           break;
       }
   }
   if(d==10000)
   {
       d = temp[temp.size()-1];
   }
   cout<<sum-d<<endl;
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
