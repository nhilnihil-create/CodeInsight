#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

void solve()
{
    ll n;
    cin >> n;

    string res = "";
    while(n)
    {
        int t = n%26;
        n /= 26;
        if(t==0)
        {
            n--;
            res += 'z';
        }
        else
        {
            res += 'a' + t-1;
        }
    }
    reverse(res.begin(), res.end());
    cout << res << endl;
}


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll t;
    solve();
    return 0;
}
