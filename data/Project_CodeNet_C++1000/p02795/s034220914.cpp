#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

vector<int> P;

int main () {
    int h, w, n;
    cin >> h >> w >> n;

    int big = max(h, w);


    cout << ceil(1.0 * n / big) << endl;
}