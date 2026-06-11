#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

void solve()
{
    int n;
    cin >> n;

    n = n%10;

    if(n == 2 || n==4 || n==7 || n==5 || n==9)
    {
        cout << "hon";
    }
    else if(n == 0 || n==1 || n==6 || n==8)
    {
        cout << "pon";
    }
    else
    {
        cout << "bon";
    }
}


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll t;
    solve();
    return 0;
}
