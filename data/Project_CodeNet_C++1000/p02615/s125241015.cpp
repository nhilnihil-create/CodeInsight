#include <bits/stdc++.h>

using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;
typedef pair<int,int> pii;
priority_queue<pii> q;
bool cmp(int a, int b) {return a > b;}
int n, a[200020];
ll res;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1, cmp);
    q.push( pii(a[2], a[1]) );
    if (n == 2) cout << a[1];
    else {
        q.push( pii(a[3], a[2]) );
        q.push( pii(a[3], a[1]) );
        res = (ll)a[1] + (ll)a[2];
        for (int i = 4; i <= n; ++i) {
            res += q.top().first;
            q.push( pii(a[i], q.top().first) );
            q.push( pii(a[i], q.top().second) );
            q.pop();
        }
        cout << res;
    }
    return 0;
}
