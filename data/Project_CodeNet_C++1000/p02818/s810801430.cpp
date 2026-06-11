#include<bits/stdc++.h>

using namespace std;

#define TC ll t; cin >> t; while(t--)
typedef long long ll;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll a,b,k;
    cin >> a >> b >> k;
    a-=k;
    if(a<0)
    {
        b+=a; a=0;
    }
    if(b<0) b=0;
    cout << a << " " << b << endl;
    return 0;
}
