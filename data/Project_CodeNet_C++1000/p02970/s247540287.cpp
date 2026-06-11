#include <iostream>
#include <cmath>

using namespace std;

int solve() {
    double n, d; cin >> n >> d;
    
    return ceil(n / (1.0 + 2.0 * d));
}

int main() {
    cout << solve() << endl;
}