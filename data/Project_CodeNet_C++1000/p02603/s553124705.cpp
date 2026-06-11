#include <iostream>
#include <vector>
using namespace std;
int main() {
    long long  n, m = 1000; cin >> n;
    vector<long long> a(n);
    for(long long &c : a) {
        cin >> c;
    }
    for(int i = 0; i < n - 1; ++i) {
        if(a.at(i) < a.at(i + 1)) {
            long long c = m / a.at(i);
            m += c * (a.at(i + 1) - a.at(i));
        }
    }
    cout << m << endl;
}