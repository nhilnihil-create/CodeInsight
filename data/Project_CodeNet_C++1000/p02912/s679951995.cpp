#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;

    priority_queue<int> pq;

    while (n--)
    {
        int x;
        cin >> x;
        pq.push(x);
    }

    while (m--)
    {
        int t = pq.top();
        pq.pop();
        pq.push(t / 2);
    }

    long long res = 0;

    while (pq.size())
    {
        res += pq.top();
        pq.pop();
    }

    cout << res;
}