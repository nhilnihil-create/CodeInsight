#include <bits/stdc++.h>
#include <numeric>
using namespace std;
#define ll long long
#define mod 100000007
#define rep(i, n) for (int i = 0; i < n; ++i)
using Graph = vector<vector<int>>;
#define grepq priority_queue<double, std::vector<double>, std::greater<double>>
#define all(v) v.begin(),v.end()
#define PI acos(-1)

const ll INF = 10010001010;

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

int main(){
    int N;
    cin >> N;
    vector<int> P(N);
    int ans = 0;
    for (int i = 0; i < N;i++)
    {
        cin >> P[i];
    }
    for (int i = 1; i < N-1;i++)
    {
        if(P[i-1] < P[i] && P[i] < P[i+1] || P[i+1] < P[i] && P[i] < P[i-1]){
            ans++;
        }
    }
    cout << ans << endl;
}
