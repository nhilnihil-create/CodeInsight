#include<bits/stdc++.h>
using namespace std;

#define ff                   first
#define ss                   second
#define ll                  long long int
#define pii                  pair<int,int>
#define pb                   push_back
#define rep(i,a,b)           for(int i=a;i<b;i++)
#define t(x)                 int t; cin>>t; while(t--)
#define vi                   vector<int>
#define mii                  map<int,int>
#define min3(a, b, c)        min(min(a, b), c)
#define min4(a, b, c, d)     min(min(a, b), min(c, d))
#define max3(a, b, c)        max(max(a, b), c)
#define max4(a, b, c, d)     max(max(a, b), max(c, d))
#define ps(x,y)              fixed<<setprecision(y)<<x
#define setbits(x)           __builtin_popcountll(x)
#define zrobits(x)           __builtin_ctzll(x)
#define all(x)               x.begin(),x.end()
#define FIO                  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                      rng(chrono::steady_clock::now().time_since_epoch().count());

ll w, h, n;

bool isPrime(int n)
{
    if (n <= 1)  return false;
    if (n <= 3)  return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}
ll power(ll x, ll y)
{
    int res = 1;      // Initialize result

    // Update x if it is more than or
    // equal to p

    if (x == 0) return 0; // In case x is divisible by p;

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) ;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) ;
    }
    return res;
}


int main()
{
    FIO;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif


    string s;
    cin >> s;
    int l = s.size();
    if (s[l - 1] == 's')
        cout << s << "es";
    else if (s[l - 1] != 's')
        cout << s << "s";



}