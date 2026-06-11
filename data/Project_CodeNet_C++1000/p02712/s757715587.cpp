#include<bits/stdc++.h>

using namespace std;

#define TC ll t; cin >> t; while(t--)
typedef long long ll;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n,m;
    cin >> n;
    m=n*(n+1)/2;
    for(int i=1;3*i<=n;i++)
    {
        m-=3*i;
        if(5*i<=n) m-=5*i;
        if(15*i<=n) m+=15*i;
    }
    cout << m << endl;
    return 0;
}
