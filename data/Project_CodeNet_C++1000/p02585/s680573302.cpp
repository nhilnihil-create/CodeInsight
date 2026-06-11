#include <bits/stdc++.h>

#define F first 
#define S second
#define PB push_back
#define ALL(x) x.begin(), x.end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 100010, M = 1010;

int n, k;
int nxt[N], c[N];

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i ++ ) cin >> nxt[i];
    for (int i = 1; i <= n; i ++ ) cin >> c[i];

    LL res = -1e18;
    for (int i = 1; i <= n; i ++ )
    {
        int cycle_cnt = 0, v = i;
        LL cycle_sum = 0;
        while (true)
        {
            cycle_cnt ++ ;
            cycle_sum += c[v];
            v = nxt[v];
            if (v == i) break;
        }

        int cnt = 0;
        LL sum = 0;
        v = i;
        while (true)
        {
            cnt ++ ;
            sum += c[v];
            if (cnt > k) break;
            
            int num = (k - cnt) / cycle_cnt;
            LL t = sum + max(0LL, cycle_sum) * num;
            res = max(res, t);

            v = nxt[v];
            if (v == i) break;
        }
    }
    cout << res << '\n';
    return 0;
}
