#include <bits/stdc++.h>
using namespace std;

bool func(vector<int> &a, vector<int> &b) {
    int s = 0;
    for (int i = 0, n = a.size(); i < n; i++) {
        int d = a.at(i) - b.at(i);
        s += d * d;
    }

    double r = sqrt(s);
    return r == floor(r);
}

int main() {
    int n, d;
    cin >> n >> d;

    vector<vector<int>> x(n, vector<int>(d));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < d; j++)
            cin >> x.at(i).at(j);

    int cnt = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (func(x.at(i), x.at(j)))
                cnt++;

    cout << cnt << endl;
}