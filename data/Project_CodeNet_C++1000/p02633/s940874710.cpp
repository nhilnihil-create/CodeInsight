#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define mod 1000000007
#define int long long
#define ll long long
#define EPS 0.000000001
#define ld long double
#define inf 5e18
#define N 2000005
#define K 17


int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int lcm(int a,int b)
{
    return (a * b) / gcd(a , b);
}
int32_t main()
{
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("int.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    int k;
    cin >> k;
    cout << lcm(360,k) / k;
    return 0;
    
}   