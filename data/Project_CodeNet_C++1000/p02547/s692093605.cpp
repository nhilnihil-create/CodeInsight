//in the name of god
#include <bits/stdc++.h>

using namespace std;
#define F first
#define S second

int n;
pair <int, int> d[100];

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> d[i].F >> d[i].S;
    }

    int checkcont = 0;
    for(int i = 0; i < n; i ++)
    {
        if(d[i].F == d[i].S)
        {
            checkcont ++;
        }

        else
        {
            checkcont = 0;
        }

        if(checkcont == 3)
        {
            cout << "Yes" << '\n';
            return 0;
        }
    }

    cout << "No" << '\n';
    return 0;
}