#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <string.h>
#include<algorithm>
#include <numeric>      // std::accumulate
#include <iomanip>      // std::setprecision


using namespace std;
#define ll           long long
#define all(v)       (v).begin() , (v).end()
#define v           vector <int>
#define vi           vector <ll>
#define vii          vector <pair<ll,ll>>
#define ii           pair<ll,ll>
#define sz(v)	     ((int)((v).size()))
#define lp(i,a,b)    for(int i=a;i<b;i++)
#define pb           push_back
#define pf           push_front
#define F            first
#define S            second
#define EPS			 1e-9
#define endl         "\n"
#define IOS          ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const double PI = 3.14159265358979323846;

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
    return (a.second < b.second);
}

int gcd(int a, int b) 
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
long long power(ll n, ll k) 
{
    if (k == 0) return 1;
    ll sq = (power(n, k / 2));
    sq = (sq * sq);
    if (k % 2 == 1)
        sq = (sq * n);
    return sq;
}
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
string to_binary(int x) 
{
    string s;
    while (x > 0) 
    {
        s += (x % 2 ? '1' : '0');
        x /= 2;
    }
    reverse(s.begin(), s.end());
    return s;
}
bool isPerfect(ll x)
{
    if (x < 1) 
        return false;
    ll root(round(sqrt(x)));
    return x == root * root;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    
    v kind(n);

    lp(i, 0, n)
        cin >> kind[i];

    sort(all(kind));
    int ans = 0;
    lp(i , 0 , k)
    {
        ans += kind[i];
    }

    cout << ans << "\n";

}

int main()
{
    IOS;    
    
    int tt;
    tt = 1;
    // cin >> tt;
    while (tt--)
    {
        solve();
    }
    
}
       