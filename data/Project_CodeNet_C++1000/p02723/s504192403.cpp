#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    string s;
    cin >> s;
    for(int i = 0; i<=5; i++)
    {
        if(s[2] == s[3] && s[4] == s[5])
        {
            cout << "Yes" << endl;
            break;

        }

        else
        {
            cout << "No" << endl;
            break;
        }
    }
}
