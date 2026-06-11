#include <bits/stdc++.h>

using ll = long long int;
using P = std::pair<int, int>;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rag(con) std::begin(con), std::end(con)

int main()
{
    int n;

    std::cin >> n;

    std::vector<int> a(n), b(n);

    rep(i, n)
            std::cin >>
        a[i] >> b[i];

    std::sort(rag(a));
    std::sort(rag(b));

    int l = (n % 2) ? a[n / 2] : a[n / 2] + a[n / 2 - 1];
    int r = (n % 2) ? b[n / 2] : b[n / 2] + b[n / 2 - 1];

    std::cout << (r - l + 1) << std::endl;

    return 0;
}