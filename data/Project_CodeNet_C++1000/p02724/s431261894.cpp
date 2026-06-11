#include<bits/stdc++.h>
using namespace std ;
typedef long long ll;
#define cf ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define fox(i,j,n) for( i=j;i<n;i++)
#define srtar(a,n) sort(a,a+n)
#define srtvec(v) sort(v.begin(),v.end())
#define fauto(x,t) for(auto x: t)
#define mem(n,x) memset(n, x, sizeof(n))
const double pi=acos(-1);

int main()
{
    ll n, s=0, t, i ;
    cin >> n ;
    s=s+(n/500)*1000;
    n=n-(n/500)*500;
    s=s+(n/5)*5;
    cout << s;
    return 0;
}