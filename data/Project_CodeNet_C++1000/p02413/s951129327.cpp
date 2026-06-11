#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;

int main(void) {
    int r,c,t;
    cin >> r >> c;
    vector<vector<int>> v(r, vector<int>(c));
    for(auto& v1 : v) for(auto& d : v1) cin >> d;
    for (int i=0; i<r; i++) {
        t = 0;
        for (int j=0; j<c; j++) {
            t += v[i][j];
            cout << v[i][j] << " ";
        }
        cout << t << endl;
    }
    for (int i=0; i<c; i++) {
        t = 0;
        for (int j=0; j<r; j++) {
            t += v[j][i];
        }
        cout << t << " ";
    }
    t = 0;
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            t += v[i][j];
        }
    }
    cout << t << endl;
    return 0;
}