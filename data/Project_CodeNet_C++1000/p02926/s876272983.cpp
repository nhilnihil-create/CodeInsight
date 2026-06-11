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
    for(int r = 0; r < 100; r++) {
        random_shuffle(data, data + n);
        for(int i = 0; i < n; i++) {
            double x = data[i].first, y = data[i].second, c = sqrt(pow(x, 2) + pow(y, 2));
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
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
    }
 
    cout << fixed << setprecision(20) << sol << endl;
 
    return 0;
}