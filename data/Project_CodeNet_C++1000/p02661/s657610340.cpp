#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

#define mt make_tuple
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sqr(x) ((ll)(x) * (x))

int n;

int minimalna(vpii &v)
{
    vi temp(n);

    for(int i = 0; i < n; ++i)
        temp[i] = v[i].fi;

    sort(all(temp));

    if(n % 2 == 0)
    {
        return temp[n/2-1]+temp[n/2];
    }
    else
    {
        return temp[(n+1)/2-1];
    }
}

int maksimalna(vpii &v)
{
    vi temp(n);

    for(int i = 0; i < n; ++i)
        temp[i] = v[i].se;

    sort(all(temp));

    if(n % 2 == 0)
    {
        return temp[n/2-1]+temp[n/2];
    }
    else
    {
        return temp[(n+1)/2-1];
    }
}

int main()
{
    cin >> n;

    vpii v(n);

    for(int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        v[i] = mp(a, b);
    }

    cout << maksimalna(v) - minimalna(v) + 1 << '\n';

    return 0;
}
