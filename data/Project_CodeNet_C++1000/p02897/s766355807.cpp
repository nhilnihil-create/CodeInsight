#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    double x;
    x = (N - floor(N / 2)) / N;
    
    cout << fixed << setprecision(6) << x << endl;
}