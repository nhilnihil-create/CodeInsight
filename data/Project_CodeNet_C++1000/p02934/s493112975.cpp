#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n, a; cin >> n;
    double res{0.0};
    for (int i = 0; i < n; ++i) {
        cin >> a;
        res += 1.0/static_cast<double>(a);
    }
    
    cout << setprecision(12) << 1.0/res << endl;
}