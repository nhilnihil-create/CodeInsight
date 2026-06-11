#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define REP(i,n) for(int i=0;i<(n);i++) 
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define deb(x) cout << #x << "=" << x << endl
#define disp(x) for(auto i : x) cout << i << " "; cout << endl
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
const int INF = 2e9, MOD = 1e9+7;

const int maxn = 1e5 + 5;

int n, m;
priority_queue<int> q;

int main()
{
    FIO
    
    cin >> n >> m;

    REP(i, n)
    {
        int a;
        cin >> a;
        q.push(a);
    }

    REP(i, m)
    {
        if(q.empty())
            break;
        int x = q.top();
        q.pop();
        x /= 2;
        if(x > 0)
            q.push(x);
    }

    ll ans = 0;
    while(!q.empty())
    {
        ans += q.top();
        q.pop();
    }

    cout << ans << endl;

    return 0;
}
