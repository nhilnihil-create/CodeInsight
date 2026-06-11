#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    double sum_a = 0.;
    for (int i=0; i<N; i++){
        double a; cin >> a;
        sum_a += 1.0 / a;
    }
    cout << std::fixed << std::setprecision(10) << 1.0 / sum_a << endl;
}