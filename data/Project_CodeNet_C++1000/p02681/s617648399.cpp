#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll i, temp, n,j, a[200600];
string s, t;
bool cond;
int main()
{
    //I am Monim, a tiny creature of Allah
    cin >> s;
    cin >> t;
    n = s.size();
    cond = true;
    for(i=0;i<n;i++)
    {
        if(s[i]!=t[i])
        {
            cond = false;
            break;
        }
    }
    if(cond)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}

