#include<bits/stdc++.h>
#define ll long long int
#define pii <pair<ll,ll>>
using namespace std;

void solve()
{
    ll a,b,c;
    cin >> a >> b >> c;
    ll d=b+c;
    if(d<=a)
    {
        cout << "0" << endl;
    }
    else
    {
        cout << d-a << endl;
    }
}

int main()
{
     solve();
     return 0;
}