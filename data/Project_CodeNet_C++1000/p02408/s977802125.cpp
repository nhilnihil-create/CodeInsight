#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
    /*
    vector<bool> s(14),h(14),c(14),d(14);
    int n;
    cin >> n;
    while(n--)
    {
        char  t;
        int i;
        cin >> t >> i;
        if(t=='S')
        {
            s[i] = true;
        }
        else if(t=='H')
        {
            h[i] = true;
        }
        else if(t=='C')
        {
            c[i] = true;
        }
        else if(t=='D')
        {
            d[i] = true;
        }
        for(int i=1; i<=13; i++)
        {
            if(!s[i])
            {
                cout << "S " << i << endl;
            }

        }
        for (int i = 1; i <= 13; i++)
            if (!h[i]) cout << "H " << i << endl;
        for (int i = 1; i <= 13; i++)
            if (!c[i]) cout << "C " << i << endl;
        for (int i = 1; i <= 13; i++)
            if (!d[i]) cout << "D " << i << endl;



    }
    */

    vector<bool> s(14), h(14), c(14), d(14);
    int n; cin >> n;
    while (n--) {
        string t; int i; cin >> t >> i;
        if (t == "S") s[i] = true;
        if (t == "H") h[i] = true;
        if (t == "C") c[i] = true;
        if (t == "D") d[i] = true;
    }
    for (int i = 1; i <= 13; i++)
        if (!s[i]) cout << "S " << i << endl;
    for (int i = 1; i <= 13; i++)
        if (!h[i]) cout << "H " << i << endl;
    for (int i = 1; i <= 13; i++)
        if (!c[i]) cout << "C " << i << endl;
    for (int i = 1; i <= 13; i++)
        if (!d[i]) cout << "D " << i << endl;



    return 0;
}