#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void print(const std::vector<int> &v)
{
    std::for_each(v.begin(), v.end(), [](int x) {
        std::cout << x << " ";
    });
    std::cout << std::endl;
}

int main()
{
    int N;
    cin >> N;
    vector<pair<int, int>> P;
    for (int i = 0; i < N; ++i)
    {
        int a, b;
        cin >> a >> b;
        pair<int, int> temp = make_pair(a, b);
        P.push_back(temp);
    }
    vector<int> v;
    for (int i = 0; i < N; ++i)
    {
        v.push_back(i);
    }
    double ans = 0;
    int k = 0;
    do
    {
        for (int i = 0; i < N - 1; ++i)
        {
            double x = pow(P[v[i]].first - P[v[i + 1]].first, 2);
            double y = pow(P[v[i]].second - P[v[i + 1]].second, 2);
            ans += sqrt(x + y);
        }
        ++k;
    } while (std::next_permutation(v.begin(), v.end()));
    cout << std::setprecision(10) << (double)(ans / (double)k) << endl;
}
