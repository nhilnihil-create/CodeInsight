#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

void solve()
{
    string s;
    int k;

    cin >> k >> s;

    cout << s.substr(0, k);
    if(s.length()>k)
    {
        cout << "...";
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
