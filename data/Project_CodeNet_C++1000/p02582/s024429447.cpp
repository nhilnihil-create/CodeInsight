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

    string S;
    cin >> S;

    if(S[0] == 'R' && S[1] == 'R' && S[2] == 'R')
    {
        cout << 3;
        return 0;
    }

    else if((S[0] == 'R' && S[1] == 'R' && S[2] != 'R'))
    {
        cout << 2;
        return 0;
    }

    else if((S[1] == 'R' && S[2] == 'R' && S[0] != 'R'))
    {
        cout << 2;
        return 0;
    }

    else if(S[0] == 'R' || S[1] == 'R' || S[2] == 'R')
    {
        cout << 1;
        return 0;
    }
    else if(S[0] == 'S' || S[1] == 'S' || S[2] == 'S')
    {
        cout << 0;
    }

    return 0;
}
