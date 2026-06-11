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

    string s;
    cin >> s;

    if(s[2] == s[3] && s[4] == s[5])cout << "Yes";
    else cout << "No";

    return 0;
}
