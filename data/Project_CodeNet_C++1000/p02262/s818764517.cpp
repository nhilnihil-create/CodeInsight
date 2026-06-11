#include <cmath>
#include <cstdio>
#include <deque>
#include <vector>

using namespace std;

template <typename T,
          template <typename V, typename = std::allocator<V>> class U>
void p(const U<T>& v)
{
    for (size_t i = 0; i < v.size() - 1; ++i) {
        printf("%d ", v[i]);
    }
    printf("%d\n", v[v.size() - 1]);
}

int insertionSort(vector<int>& v, int g, int cnt)
{
    for (size_t i = g; i < v.size(); ++i) {
        int e = v[i];
        int j = i - g;
        while (j >= 0 && v[j] > e) {
            v[j + g] = v[j];
            j = j - g;
            ++cnt;
        }
        v[j + g] = e;
    }
    return cnt;
}

int main()
{
    int N;
    scanf("%d", &N);
    vector<int> v;
    int t;
    for (int i = 0; i < N; ++i) {
        scanf("%d", &t);
        v.push_back(t);
    }
    int cnt = 0;

    deque<int> g = {1};
    auto lim = static_cast<int>(ceil(v.size() / 3.0));
    auto e = [](int n) { return 3 * n + 1; };
    while (true) {
        auto r = e(g[0]);
        if (r > lim) {
            break;
        }
        g.push_front(r);
    }

    for (size_t i = 0; i < g.size(); ++i) {
        cnt = insertionSort(v, g[i], cnt);
    }
    printf("%ld\n", g.size());
    p(g);
    printf("%d\n", cnt);
    for (auto&& i : v) {
        printf("%d\n", i);
    }
}