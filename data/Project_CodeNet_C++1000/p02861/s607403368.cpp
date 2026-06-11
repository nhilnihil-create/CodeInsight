#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;

    vector<int> perm(n), x(n), y(n);
    for (size_t i = 0; i < n; i++){
        perm[i] = i;
        cin >> x[i] >> y[i];
    }

    double ave = 0;
    int n_perm = 0;
    do {
        n_perm++;
        double d = 0;
        for (size_t i = 0; i < n-1; i++) {
            d += sqrt((x[perm[i+1]]-x[perm[i]]) * (x[perm[i+1]]-x[perm[i]]) + (y[perm[i+1]]-y[perm[i]]) * (y[perm[i+1]]-y[perm[i]]));
        }
        ave += d;
    } while(next_permutation(perm.begin(), perm.end()));
    ave /= n_perm;

    printf("%.10f\n", ave);
    return 0;
}
