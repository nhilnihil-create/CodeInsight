#include <iostream>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

inline int calc(int Y, int M, int D)
{
    int day = 1;
    for (int y = Y; y < 1000; y++) {
        day += (y % 3 == 0) ? 200 : 195;
    }

    day -= D;
    for (int m = 1; m <= M - 1; m++) {
        day -= (Y % 3 == 0) ? 20 : (m % 2 == 1) ? 20 : 19;
    }
    return day;
}

int main()
{
    int n;
    cin >> n;
    for (int cnt = 0; cnt < n; cnt++) {
        int y, m, d;
        cin >> y >> m >> d;
        cout << calc(y, m, d) << endl;
    }
    return 0;
}