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

    int n;
    cin >> n;
    int a[n];
    for (int i=0;i<=n-1;i++)
    {
        cin >> a[i];
    }

    int b[n];
    for (int i=0;i<=n-1;i++)
    {
        cin >> b[i];
    }

    int c[n-1];
    for (int i=0;i<=n-2;i++)
    {
        cin >> c[i];
    }

    int ans=0;
    for (int i=0;i<=n-1;i++)
    {
        int id=a[i];
        id--;
        ans=ans+b[id];

        if (i!=n-1)
        {
            int next_id=a[i+1];
            next_id--;
            if (id+1==next_id)
            {
                ans=ans+c[id];
            }
        }
    }

    cout << ans << endl;
    return 0;
}