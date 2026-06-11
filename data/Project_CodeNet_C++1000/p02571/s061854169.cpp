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

    string s,t;
    cin >> s >> t;

    int n=s.length();
    int m=t.length();

    int ans=INT_MAX;
    for (int i=0;i<=n-m;i++)
    {
        int local=0;
        for (int j=0;j<=m-1;j++)
        {
            if (s[i+j]!=t[j])
            {
                local++;
            }
        }
        ans=min(ans,local);
    }

    cout << ans << endl;

    return 0;
}
