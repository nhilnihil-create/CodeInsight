#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    int x;
    cin >> x;
    vector<int> p(1, 2);
    bool prime = false;
    int i = 3;
    if (x == 2) {
        prime = true;
    }
    while (prime == false) {
        for (auto a : p) {
            if (i % a == 0) {
                break;
            }
            if (a == p.back()) {
                p.push_back(i);
            }
        }
        if (p.back() >= x) {
            prime = true;
        }
        i++;
    }
    cout << p.back() << endl;
    return 0;
}