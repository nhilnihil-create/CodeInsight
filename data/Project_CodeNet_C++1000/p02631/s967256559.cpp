#include <bits/stdc++.h>

using ll = long long int;
using P = std::pair<int, int>;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rag(con) std::begin(con), std::end(con)

int main()
{
    int n;

    std::cin >> n;

    std::vector<int> a(n);

    int sum = 0;

    rep(i, n)
    {
        std::cin >>
            a[i];
        sum = sum ^ a[i];
    }

    rep(i, n)
    {
        std::cout << (sum ^ a[i]) << ' ';
    }
    std::cout << std::endl;

    return 0;
}