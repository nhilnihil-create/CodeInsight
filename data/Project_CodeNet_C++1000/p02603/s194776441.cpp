#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int main() {   
    int n;
    cin >> n;
    unordered_map<long long int, long long int> um1, um2;
    um1[0] = 1000;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        um2 = um1;
        for (auto p : um1) {
            long long int s = p.first, m = p.second;
            um2[0] = max(um2[0], m + a * s);
            um2[s + m / a] = max(um2[s + m / a], m % a);
        }
        um1 = um2;
    }
    cout << um1[0] << endl;
}


