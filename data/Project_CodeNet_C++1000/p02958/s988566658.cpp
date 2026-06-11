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
    vector<int> v(n + 1, 0);
    int c = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        if (v[i] != i) c++;
    }
    if (c > 2)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
}
