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

const int MAXN = 2e5;

int l[MAXN+1], r[MAXN+1];

void debug(int granica)
{
    for(int i = 1; i <= granica; ++i)
    {
        cout << l[i] << ' ';
    }
    cout << '\n';
    for(int j = 1; j <= granica; ++j)
    {
        cout << r[j] << ' ';
    }
    cout << '\n';
}

int main()
{
    int n, k, c;
    cin >> n >> k >> c;
    string s;
    cin >> s;

    int pokazivac = 1;

    for(int i = 0; i < n && pokazivac <= k; ++i)
    {
        if(s[i]=='o')
        {
            l[pokazivac++]=i+1;
            i += c;
        }
    }

    pokazivac = k;

    for(int i = n-1; i >= 0 && pokazivac > 0; --i)
    {
        if(s[i]=='o')
        {
            r[pokazivac--]=i+1;
            i -= c;
        }
    }

    //debug(20);

    for(int i = 1; i <= k; ++i)
    {
        if(l[i]==r[i])
        {
            cout << l[i] << '\n';
        }
    }

    return 0;
}
