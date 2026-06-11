#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> b(n - 1);
    for (int i = 0; i < n - 1; i++)
        cin >> b.at(i);

    vector<int> a(n);
    a.at(0) = b.at(0);
    a.at(n - 1) = b.at(n - 2);
    for (int i = 1; i < n - 1; i++)
        if (b.at(i - 1) < b.at(i))
            a.at(i) = b.at(i - 1);
        else
            a.at(i) = b.at(i);
    
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += a.at(i);
        // cout << a.at(i) << ' ';
    }
    // cout << endl;

    cout << s << endl;
}