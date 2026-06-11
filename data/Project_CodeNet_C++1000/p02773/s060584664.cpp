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
    int t, cnt = 0;

    map< string, int> A;

    cin>> t;

    for(int i = 0; i< t; i++)
    {
        string tmp;

        cin>> tmp;

        A[tmp]++;

        cnt = max(cnt, A[tmp]);
    }

    auto it = A.begin();

    while( it != A.end())
    {
        if(cnt == it-> second)
        {
            cout << it->first<< endl;
        }

        it++;
    }

    return 0;
}
