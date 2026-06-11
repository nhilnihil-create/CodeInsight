#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int solve() {
    int n, d; cin >> n >> d;
    vector<vector<int>> nums;
    for (int i = 0; i < n; ++i) {
        vector<int> row(d);
        for (int j = 0; j < d; ++j) {
            cin >> row[j];
        }
        nums.push_back(row);
    }
    
    int res{0};
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            double dist = 0.0;
            for (int k = 0; k < d; ++k) {
                dist += pow(nums[i][k] - nums[j][k], 2);
            }
            if (sqrt(dist) == floor(sqrt(dist))) {
                res++;
            }
        }
    }
    
    return res;
}

int main() {
    cout << solve() << endl;
}