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
const int mod = 998244353;
const int N = 1e5 + 5;



int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    double res = 0;
    priority_queue<double, vector<double>, greater<double>> pq;
    FOR(i, 0, n)
    {
        double a; cin >> a;
        pq.push(a);
    }
    res = pq.top();
    pq.pop();
    while (!pq.empty())
    {
        res += pq.top();
        res /= 2;
        pq.pop();
    }
    cout << res;
    return 0;
}

