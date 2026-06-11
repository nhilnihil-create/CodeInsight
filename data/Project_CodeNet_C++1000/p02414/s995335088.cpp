#include <cstdio>
#include <vector>

using namespace std;

using i64=long long;
using Vector=vector<i64>;
using Matrix=vector<Vector>;

Matrix operator*(Matrix &a, Matrix &b) {
    Matrix c(a.size(), Vector(b[0].size()));
    for (size_t i=0; i<a.size(); ++i)
        for (size_t j=0; j<b[0].size(); ++j)
            for (size_t k=0; k<b.size(); ++k)
                c[i][j] += a[i][k] * b[k][j];

    return c;
}

int main() {
    size_t n, m, l;
    scanf("%zu %zu %zu", &n, &m, &l);

    Matrix a(n, Vector(m));
    for (size_t i=0; i<n; ++i)
        for (size_t j=0; j<m; ++j)
            scanf("%d", &a[i][j]);

    Matrix b(m, Vector(l));
    for (size_t j=0; j<m; ++j)
        for (size_t k=0; k<l; ++k)
            scanf("%d", &b[j][k]);

    Matrix c=a*b;
    for (size_t i=0; i<n; ++i)
        for (size_t k=0; k<l; ++k)
            printf("%lld%c", c[i][k], k<l-1? ' ':'\n');

    return 0;
}