#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <numeric>
#include <vector>

using namespace std;

int main()
{
    deque<int> d;
    vector<int> v;
    constexpr auto size = 123456 * 2;
    d.resize(size - 1);
    iota(begin(d), end(d), 2);
    const int cut = sqrt(size);
    while (d[0] < cut) {
        v.push_back(d[0]);
        d.erase(remove_if(begin(d),
                          end(d), [n = d[0]](int x) { return x % n == 0; }),
                end(d));
    }
    v.insert(end(v), begin(d), end(d));
    while (true) {
        int n;
        scanf("%d", &n);
        if (n == 0) {
            break;
        }
        auto r = count_if(begin(v), end(v),
                          [n](int x) { return n < x && x <= 2 * n; });
        printf("%ld\n", r);
    }
}