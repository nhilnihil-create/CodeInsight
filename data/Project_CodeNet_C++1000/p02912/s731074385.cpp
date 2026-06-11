#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_set>
#include <map>           // sorted map so O(logn)
#include <unordered_map> // O(1)
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    priority_queue<int> pq;
    ll sum = 0;
    rep(i, n)
    {
        int x;
        cin >> x;
        sum += x;
        pq.push(x);
    }
    rep(i, m)
    {
        int r = pq.top();
        pq.pop();
        int rr = r / 2;

        sum -= r - rr;
        pq.push(rr);
    }
    cout << sum << endl;
}