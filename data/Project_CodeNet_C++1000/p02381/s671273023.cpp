#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

double stdev(vector<double> s) {
    double ave=0, sq_ave=0;
    for (double d: s) {
        ave += d;
        sq_ave += d*d;
    }
    ave /= s.size();
    sq_ave /= s.size();

    return sqrt(sq_ave-ave*ave);
}

int main() {
    while (true) {
        size_t n;
        scanf("%zu", &n);
        if (!n) return 0;

        vector<double> s(n);
        for (size_t i=0; i<n; ++i)
            scanf("%lf", &s[i]);

        printf("%.12f\n", stdev(s));
    }
}