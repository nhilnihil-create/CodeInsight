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
	int a, b;
    cin >> a >> b;
    if ((a + b) % 2 == 1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    cout << (a + b) / 2 << endl;
}
