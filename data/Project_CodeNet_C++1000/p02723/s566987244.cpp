#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define Opy ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)

typedef long long ll;

int main()
{
    //Opy;

/*-------------------------------------------------
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
-------------------------------------------------*/
    string A;

    cin>> A;

    if(A[2] == A[3] && A[4] == A[5]) cout<< "Yes\n";

    else cout<< "No\n";

    return 0;
}
