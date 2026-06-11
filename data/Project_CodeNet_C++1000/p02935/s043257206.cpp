#include <bits/stdc++.h>
using namespace std;

int main() {
    double ans = 0;
    int N;
    cin >> N;
    multiset<double> v;
    for(int i = 0; i < N; i++) {
        double x;
        cin >> x;
        v.insert(x);
    }
    for(int i = 0; i < N - 1; i++) {
        double x = *v.begin();
        v.erase(v.begin());
        x /= double(2);
        double y = *v.begin();
        v.erase(v.begin());
        y /= double(2);
        v.insert(x + y);
    }
    ans = *v.begin();
    cout << fixed << setprecision(6) << ans << endl;
}