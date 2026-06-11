#include<bits/stdc++.h>
#define endl "\n"
#define PI acos(-1)
#define BMW_GTR ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)

typedef long long ll;
using namespace std;

//ll const n = 50005;

int main()
{
    BMW_GTR;

    int X;
    cin >> X;

    cout << (X / 500) * 1000 + ((X % 500) / 5) * 5;

    return 0;
}
