#include <bits/stdc++.h>
#include <numeric>
using namespace std;
#define ll long long
#define mod 1000000007
#define rep(i, n) for (int i = 0; i < n; ++i)
using Graph = vector<vector<int>>;
#define grepq priority_queue<double, std::vector<double>, std::greater<double>>
#define all(v) v.begin(), v.end()
#define PI acos(-1)

const ll INF = 10010001010;
const int inf = 2000000000;
ll lcm(ll a, ll b)
{
    return a * b / __gcd(a, b);
}

typedef tuple<string, int, int> TUP;

bool tuplesort(const TUP &right, const TUP &left)
{
    if (get<0>(right) != get<0>(left))
    {
        return get<0>(left) < get<0>(right);
    }
    if (get<1>(left) != get<1>(right))
    {
        return get<1>(left) > get<1>(right);
    }
    return get<2>(left) < get<2>(right);
}
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

ll nCr(int n, int r)
{
    ll ans = 1;
    for (int i = n; i > n - r; --i)
    {
        ans = ans * i;
    }
    for (int i = 1; i < r + 1; ++i)
    {
        ans = ans / i;
    }
    return ans;
}

int main()
{
    int N,R;
    cin >> N >> R;
    if(N > 9){
        cout << R << endl;
    }
    else{
        cout << R + (100 * (10 - N)) << endl;
    }
}
