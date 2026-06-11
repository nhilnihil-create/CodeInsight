#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    pair<int, int> data[n];

    for(int i = 0; i < n; i++) {
        cin >> data[i].first >> data[i].second;
    }
    

    double sol = 0;
    for(int r = 0; r < 100000; r++) {
        random_shuffle(data, data + n);
        double x = data[0].first, y = data[0].second, c = sqrt(pow(x, 2) + pow(y, 2));
        for(int j = 1; j < n; j++) {
            x += data[j].first;
            y += data[j].second;
            double length = sqrt(pow(x, 2) + pow(y, 2));
            if(length > c) c = length;
            else {
                x -= data[j].first;
                y -= data[j].second;
            }
        }
        sol = max(c, sol);
    }

    cout << fixed << setprecision(20) << sol << endl;

    return 0;
}