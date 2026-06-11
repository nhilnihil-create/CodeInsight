#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <stack>
#include <queue>
using namespace std;
using ll = long long;
using P = pair<int, int>;
vector<int> num;

int main()
{
    int n, m;
    cin >> n >> m;
    priority_queue<ll> pq;
    for (int i = 0; i < n; ++i)
    {
        ll a;
        cin >> a;
        pq.push(a);
    }

    while(m)
    {
        ll a = pq.top();
        pq.pop();
        a /= 2;
        pq.push(a);
        --m;
    }

    ll ans = 0;
    while(!pq.empty())
    {
        ll a = pq.top();
        pq.pop();
        ans += a;
    }

    cout << ans << endl;
    return 0;
}
