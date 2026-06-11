#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

    string s;

    cin >> s;

    int rain = 0;

    for(int i=0; i<3; i++)
    {
        if(s[i] == 'R')
        {
            rain++;
        }
    }

    if(rain == 3)
    {
        cout << 3;
    }

    else if(rain == 1)
    {
        cout << 1;
    }

    else if(rain == 2)
    {
        if(s[0] == 'R' && s[1] == 'R' || s[1] == 'R' && s[2] == 'R')
        {
            cout << 2;
        }

        else
        {
            cout << 1;
        }
    }

    else if(rain == 0)
    {
        cout << 0;
    }
}







