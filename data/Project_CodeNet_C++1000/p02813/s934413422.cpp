#include <bits/stdc++.h>
#include <limits>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
#define fi(i,n) for( ll i=0 ; i<n ; i++ )
#define f(i, a, b) for( ll i=a ; i<b ; i++ )
#define vi vector<int>
#define pb push_back
#define MOD 1000000007
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);

}
ll fact(ll n)
{
    ll ans = 1e14;
    for(ll i = 1; i<=sqrt(n); i++)
    {
        if(n%i==0)
        {
            ll sol = (i - 1) + (n/i - 1);
            ans = min(ans,sol);
        }
    }
    return ans;
}
int visited[200000] = {0};
vector<vector<int> > v(200000);
int dfs(int x)
{
    int ans = 0;
    if(visited[x]==0)
    {
        visited[x] = 1;
        ans++;
        int a = v[x].size();
        for(int j = 0; j<a; j++)
        {
            int data = v[x][j];
            ans = ans + dfs(data);
        }
    }
    return ans;
}
void primefactors(int n)
{
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            cout << i << " ";
            n = n/i;
        }
    }

    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
        cout << n << " ";

}
double fib(int n)
{
    double sol1,sol2;
    sol1 = (1 + sqrt(5))/2;
    sol2 = (1 - sqrt(5))/2;
    sol1 = pow(sol1,n);
    sol2 = pow(sol2,n);
    double ans = sol1 - sol2;
    ans = ans/sqrt(5);
    //ans = int(ans);
    return ans;
}

ll digits(ll n)
{
    return floor(log10(double(n))) + 1;
}

ll index(ll n)
{
    n = double(n);
    double sol = n*n + n;
    sol = sol*2 + 1;
    double ans = -1 + sqrt(sol);
    ans = ans/2;
    ans = ll(ans);
    return ans;
}
vector<ll> SieveOfEratosthenes(ll n,ll a)
{

    bool prime[n+1];
    memset(prime, true, sizeof(prime));
    vector<ll>v;
    for (ll p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {

            for (ll i=p*p; i<=n; i += p)
                prime[i] = false;
        }
    }

    for (ll p= a; p<=n; p++)
       if (prime[p])
          v.push_back(p);
    return v;
}
int ab =0;
int temp1,temp2;
void permute(string a, int l, int r,string x,string y)
{
    // Base case
    if (l == r)
    {
        ab++;
        if(x==y && a==x)
        {
            temp1 = ab;
            temp2 = ab;
        }
        else
        {
            if(a==x)
            {
                temp1 = ab;
            }
            else if(a == y)
            {
                temp2 = ab;
            }
        }



    }
    else
    {
        // Permutations made
        for (int i = l; i <= r; i++)
        {

            // Swapping done
            swap(a[l], a[i]);

            // Recursion called
            permute(a, l+1, r,x,y);

            //backtrack
            //swap(a[l], a[i]);
        }
    }
}
int main()
{

    int n;
    cin>>n;
    string s = "" ;
    f(i,1,n + 1)
    {
        char x = i + '0';
        s += x;
    }
    string x,y;
    fi(i,n)
    {
        int m;
        cin>>m;
        char a = m + '0';
        x += a;

    }
    fi(i,n)
    {
        int m;
        cin>>m;
        char a = m + '0';
        y += a;

    }
    permute(s,0,n - 1,x,y);
    cout<<abs(temp1 - temp2);
}
