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

const int MAXN = 1e5 + 10;
vi svakiDan[MAXN];

int main()
{
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        if(m - a >= 0)
        {
            svakiDan[m-a].pb(b);
        }
    }

    int resenje = 0;

    priority_queue<int> pq;

    for(int i = m; i >= 0; --i)
    {
        for(int j = 0; j < (int)svakiDan[i].size(); ++j)
        {
            pq.push(svakiDan[i][j]);
        }

        if(!pq.empty())
        {
            resenje += pq.top();
            pq.pop();
        }
    }

    cout << resenje << '\n';

    return 0;
}
