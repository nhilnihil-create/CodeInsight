#include <bits/stdc++.h>
#include <numeric>
using namespace std;
#define ll long long
#define mod 100000007
#define rep(i, n) for (int i = 0; i < n; ++i)
using Graph = vector<vector<int>>;
#define grepq priority_queue<double, std::vector<double>, std::greater<double>>
#define all(v) v.begin(),v.end()
ll INF = 10010001010;

ll lcm(ll a,ll b)
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

int main(){
    string S;
    cin >> S;
    string s, t = "";
    int ans = 0;
    for (int i = 0; i < S.size();i++)
    {
        s.push_back(S[i]);
        if (s != t)
        {
            t = s;
            ans++;
            s = "";
        }
    }
    cout << ans<< endl;
}
