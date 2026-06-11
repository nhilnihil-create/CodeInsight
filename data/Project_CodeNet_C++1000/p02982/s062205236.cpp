#include <iostream>
#include <math.h>
#include <vector>
using namespace std;


float distance(vector<int> a, vector<int> b, int d) {
    float res = 0.0;
    for (size_t i=0; i<d; i++) {
        res += (a[i] - b[i]) * (a[i] - b[i]);
    }
    // cout << "dist: " << res << endl;
    return sqrt(res);
}

int main() {
    int n, d;
    cin >> n >> d;
    vector<vector<int>> points(n, vector<int>(d,0));
    for (int i=0; i<n; i++) {
        for (int j=0; j<d; j++) {
            cin >> points[i][j];
        }
    }
    float dist = 0.0;
    int cnt = 0;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            // cout << i << j << endl;
            dist = distance(points[i], points[j], d);
            // cout << dist;
            if (floor(dist) == dist) cnt++;
        }
    }
    cout << cnt;
    return 0;
}
