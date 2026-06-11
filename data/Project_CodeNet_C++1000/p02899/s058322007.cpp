#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> y(n);

    for (int i = 0; i < n; i++)
    {
        cin >> x.at(i);
        y.at(x.at(i)-1) = i+1;
    }
    for (int i = 0; i < n; i++)
    {
        cout << y.at(i) << " ";
    }
    cout << endl;
}