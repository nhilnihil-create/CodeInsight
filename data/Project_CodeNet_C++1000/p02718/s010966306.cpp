#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <queue>
#include <deque>
#include <string>
#include <sstream>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <stack>
#include <cstdio>
#include <climits>
#include <tuple>
#include <ctime>
#include <cstring>
#define FOR(i,a,n) for (int i = a; i < n; i++)
#define IFOR(i,n,a) for (int i = n; i >= a; i--)
#define mp make_pair
#define full(a) a.begin(), a.end()
#define sz(x) ((int)(x).size())
#define pii pair<int, int>
#define trav(a,x) for (auto& a : x)
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
using namespace std;
const ll mod = 998244353;



int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    priority_queue<int> pq;
    int sum = 0;
    FOR(i, 0, n)
    {
        int a; cin >> a;
        pq.push(a);
        sum += a;
    }
    int req = sum / (4 * m);
    if (sum % (4 * m) != 0) req++;
    while (m--)
    {
        int num = pq.top();
        pq.pop();
        if (num < req)
        {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}










