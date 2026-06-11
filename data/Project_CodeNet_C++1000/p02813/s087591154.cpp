#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < b; i++)
int N;
void print(const std::vector<int> &v)
{
    std::for_each(v.begin(), v.end(), [](int x) {
        std::cout << x << " ";
    });
    std::cout << std::endl;
}
int fact(int n)
{
    int i, facto = 1;

    if (n == 0 || n == 1)
    {
        facto = 1;
    }
    else
    {
        for (i = 1; i <= n; i++)
        {
            facto = facto * i;
        }
    }

    return facto;
}
int main()
{
    cin >> N;
    vector<int> P(N);
    vector<int> Q(N);

    rep(i, 0, N)
    {
        cin >> P[i];
    }
    rep(i, 0, N)
    {
        cin >> Q[i];
    }
    int p1 = fact(N);
    int q1 = fact(N);

    do
    {
        p1--;
    } while (std::next_permutation(P.begin(), P.end()));
    do
    {
        q1--;
    } while (std::next_permutation(Q.begin(), Q.end()));

    cout << abs(p1 - q1) << endl;
    return 0;
}
