#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define f(i, n)         for(int i=0; i<n; i++)
#define fo(i, k, n)     for(int i=k; i<n; i++)
#define forr(i, a, b)   for(int i=a; i<=b; i++)
#define rf(i,n)         for(int i=n;i>=0;i--)
typedef unsigned long long ull;
typedef pair<int ,int> pr;
#define MAX 100005
#define INF 1000000009
#define   sq(n)         (n*n)
#define p(n) cout<<n<<endl
#define pb push_back
#define py cout<<"YES"<<endl;
#define pn cout<<"NO"<<endl;
ll mod =1e9+7;
#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
ll lcm ( ll a, ll b )
{
    return ( a / __gcd ( a, b ) ) * b;
}


ll modpow(ll a,ll n, ll mod)
{
    ll res = 1;
    while(n>0)
    {
        if (n%2==1)
        {
            res = res * a % mod;
        }
        a = a * a % mod;
        n/=2;
    }
    return res;
}

int bin_ser(int *a,int n,int x)
{
    int l=0;
    int h=n-1;
    while(l<=h)
    {
        int mid=l+((h-l)/2);
        if(a[mid]==x)
        {
          return mid;
        }
        else if(a[mid]<x)
        {
            l=mid+1;
        }
        else
        {
            h=mid-1;
        }
    }
}

int main()
{
    __FastIO;

        int n,x,t;
        cin>>n>>x>>t;
        float p=n/(float)x;
        int q=ceil(p);
        p(q*t);

    return 0;
}


