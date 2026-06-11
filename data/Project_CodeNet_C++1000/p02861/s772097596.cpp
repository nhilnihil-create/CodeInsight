#include<bits/stdc++.h>
#define endl "\n"
#define PI acos(-1)
#define BMW_GTR ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)

typedef long long ll;
using namespace std;

//ll const n = 50005;

ll fact(ll N)
{
    ll ans = 1;
    for(int i = 1; i <= N; i++)
    {
        ans *= i;
    }

    return ans;
}

int main()
{
    BMW_GTR;

    int N;
    cin >> N;

    vector<pair<long double, long double>> arr;
    long double ans = 0.00;

    for(int i = 0; i < N; i++)
    {
        long double x, y;
        cin >> x >> y;

        arr.push_back(make_pair(x, y));
    }

    sort(arr.begin(), arr.end());

    do
    {
        for(int i = 0; i < N - 1; i++)
            {
                ans += sqrt((arr[i].first - arr[i + 1].first) * (arr[i].first - arr[i + 1].first) + (arr[i].second - arr[i + 1].second) * (arr[i].second - arr[i + 1].second));
            }
    }while(next_permutation(arr.begin(), arr.end()));

    cout << fixed << setprecision(10) << ans / (fact(N) * 1.00);

    return 0;
}
