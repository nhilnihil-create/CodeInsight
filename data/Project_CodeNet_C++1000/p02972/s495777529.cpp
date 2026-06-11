#include <bits/stdc++.h>

using namespace std;
#define  ll long long
#define ld long double
#define f first
#define s second
const int N = 2e5+5;

ll n , a[N] , val[N];


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> a[i];

    for(int i=n; i>0; i--)
    {
        ll sum = 0;
        for(int j=i; j<=n; j+=i) //contains ball
            sum += val[j];

        if (sum%2 == a[i]) continue;
        val[i] = 1;
    }


    for(int i=1; i<=n; i++)
    {
        ll sum=0;
        for(int j=i; j<=n; j+=i)
        {
            sum += val[j];
        }
        if (a[i] != sum%2) return cout << "-1\n" , 0;
    }
    vector<ll> ans;

    for(int i=1; i<=n; i++)
        if (val[i]) ans.push_back(i);

    cout << ans.size() << '\n';
    for(auto i : ans)
        cout << i << ' ';

    return 0;
}