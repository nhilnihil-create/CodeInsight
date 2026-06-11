#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, x;
    long long ans = 0;
    priority_queue<int> q;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        ans += x;
        q.push(x);
    }
    for (int i = 0; i < m; i++)
    {
        ans -= ((q.top()+1)/2);
        q.push(q.top()/2);
        q.pop();
    }
    cout << ans;
}