#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long double> data(n);
    long double sum = 0;
    for (int i = 0; i < n; i++){
        cin >> data.at(i);
        sum += 1 / data.at(i);
    }
    cout << fixed << setprecision(10);
    cout << 1 / sum << endl;
}