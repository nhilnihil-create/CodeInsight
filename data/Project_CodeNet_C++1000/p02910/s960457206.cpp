#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl "\n"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);

    string s;
    cin >> s;

    bool ans=true;
    for (int i=0;i<=s.length()-1;i++)
    {
        if ((i%2==0)&&(s[i]=='L'))
        {
            ans=false;
        }
        else if ((i%2==1)&&(s[i]=='R'))
        {
            ans=false;
        }
    }

    if (ans)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}