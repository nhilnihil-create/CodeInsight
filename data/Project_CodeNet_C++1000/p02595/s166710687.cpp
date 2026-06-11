#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define rep(i,n) for(int i = 0; i , (n); ++i)
using ll = long long;
using namespace std;
int sum(int n) {
    if (n == 0) {
        return 0;
    }

    int s = sum(n - 1);
    return s + n;
}
int main() {
    ll N, D, a, b, count=0;
    double c;
    cin >> N >> D;
    vector<int>x(N);
    vector<int>y(N);
    for (int i = 0;i < N;i++) {
        cin >> x.at(i) >> y.at(i);
    }
    
    for (int i = 0;i < N;i++) {
        a = x.at(i);
        a *= a;
        b = y.at(i);
        b *= b;
        c = sqrt(a + b);
        if (c <= D) {
            count++;
        }
    }
    cout << count;
}
