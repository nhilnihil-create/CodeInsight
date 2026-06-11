#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
typedef long long int ll;
#define rep(i,n) for(int i = 0; i < n; i++)

double dist (int i, int j, vector<int> x, vector<int> y) {
    return pow(pow((x[i] - x[j]), 2) + pow((y[i] - y[j]), 2), 0.5);
}

int main() {
    int n;
    cin >> n;

    vector<int> point_x, point_y;
    vector<int> idx;
    rep(i, n) {
        int x, y;
        cin >> x >> y;
        point_x.emplace_back(x);
        point_y.emplace_back(y);
        idx.emplace_back(i);
    }

    double total = 0;
    int cnt = 0;
    do {
        for (int i = 0; i < idx.size()-1; i++) {
            total += dist(idx[i], idx[i+1], point_x, point_y);
        }
    } while(next_permutation(idx.begin(), idx.end()));
    

    int f = 1;
    for(int i = 2;i <= n;i++)f *= i;

    // cout << total / f << endl;
    printf("%0.10f\n", total / f);
}