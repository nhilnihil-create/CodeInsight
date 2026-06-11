#include <bits/stdc++.h>

using namespace std;
#define  ll long long
#define ld long double
#define f first
#define s second

ll a[55] , a2[55] , n;

bool check()
{
    for(int i=1; i<n; i++)
        if (a[i+1] < a[i]) return 0;
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> a[i] , a2[i]=a[i];

    if (check()) return cout << "YES\n" , 0;

    for(int i=1; i<=n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            swap(a[i],a[j]);
            for(int k=1; k<=n; k++)
                a2[k] = a[k];
            if (check())
                return cout << "YES\n" , 0;
            swap(a[i],a[j]);
        }
    }

    cout << "NO\n";
  //

    return 0;
}