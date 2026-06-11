#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

template <class RandomIt>
size_t isort(RandomIt first, RandomIt last, ptrdiff_t g) {
    using T=typename RandomIt::value_type;
    size_t count_=0;
    for (RandomIt it=first+g; it<last; ++it) {
        T v=*it;
        RandomIt it2;
        for (it2=it-g; it2>=first&&v<*it2; it2-=g) {
            it2[g] = it2[0];
            ++count_;
        }
        it2[g] = v;
    }
    return count_;
}

template <class RandomIt>
size_t shsort(RandomIt first, RandomIt last) {
    /* Shell sort */
    size_t count_=0, m=last-first;

    vector<ptrdiff_t> g; g.push_back(1);
    for (size_t h=4; h<=m&&g.size()<100; ++(h*=3))
        g.push_back(h);

    reverse(g.begin(), g.end());

    printf("%zu\n", g.size());
    for (size_t i=0; i<g.size(); ++i) {
        printf("%zu%c", g[i], i<g.size()-1? ' ':'\n');
        count_ += isort(first, last, g[i]);
    }

    return count_;
}

int main() {
    size_t N;
    scanf("%zu", &N);

    vector<int> A(N);
    for (size_t i=0; i<N; ++i)
        scanf("%d", &A[i]);

    size_t t=shsort(A.begin(), A.end());

    printf("%zu\n", t);
    for (size_t i=0; i<N; ++i)
        printf("%d\n", A[i]);

    return 0;
}