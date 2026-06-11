#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define Opy ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)

typedef long long ll;

int main()
{
    Opy;

/*-------------------------------------------------
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
-------------------------------------------------*/
    int n;

    cin>> n;

    map< ll, ll> B;

    for(int i = 0; i < n; i++)
    {
        ll tmp;

        cin>> tmp;

        B[tmp]++;
    }

    auto it = B.begin();

    while(it != B.end())
    {
        if(it->second > 1)
        {
            cout<< "NO\n";
            return 0;
        }

        it++;
    }

    cout<< "YES\n";

    return 0;
}
