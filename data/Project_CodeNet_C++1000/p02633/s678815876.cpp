#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#include<bits/stdc++.h>
#include<unordered_map>
#define M 1000000007
#define T 998244353
#define pi 3.14159265
#define N 100003
#define inf 1000000002
#define ll long long
#define fo(i, a, b) for(i=a; i<=b; i++)
#define ro(i, b, a) for(i=b; i>=a; i--)
#define foe(it, x) for(auto it=x.begin(); it!=x.end(); it++)
#define ff first
#define ss second
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define fil(x, y) memset(x, y, sizeof(x))
#define deb(x) cout << #x << " " << x << "\n"

using namespace std;

int gcd(int a, int b){
    if(a==0)return b;
    return gcd(b%a,a);
}
int lcm(int a, int b){
    return (a*b)/gcd(a,b);
}
void solve()
{
    int x;cin>>x;
    cout << lcm(360,x)/x << "\n";
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifdef LOCAL 
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif

    //int _t;cin >> _t; while(_t--)
    solve();
    return 0;
}
