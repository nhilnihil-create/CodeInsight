#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <unordered_map>
#include <iomanip>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int h[n];
    for (int i = 0; i < n; i++) cin >> h[i];

    sort(h, h + n);
    long long count = 0;
    for (int i = 0; i < n - k; i++) count += h[i];
    cout << count << endl;

    return 0;
}