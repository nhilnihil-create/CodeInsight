#include <bits/stdc++.h>

using namespace std;
#define  ll long long
#define ld long double
#define f first
#define s second

string s;
char lst = '0';
ll ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> s;

    for(int i=0; i<(int)s.size(); i++)
    {
        if (s[i] != lst)
        {
            lst=s[i];
            ans++;
        }
        else
        {
            if (i < (int)s.size()-1)
            {
                ans++ , i++;
                lst='0';
            }
            else break;
        }
    }

    cout << ans << '\n';
  //

    return 0;
}