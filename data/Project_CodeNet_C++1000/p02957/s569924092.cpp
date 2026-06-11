#include<bits/stdc++.h>
#define ll long long int
#define pii <pair<ll,ll>>
using namespace std;

void solve()
{
    ll a,b;
    cin >> a >> b;
    ll avg=(a+b)/2;
    if((a+b)%2 !=0)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
        cout << avg << endl;
}

int main()
{
     solve();
     return 0;
}