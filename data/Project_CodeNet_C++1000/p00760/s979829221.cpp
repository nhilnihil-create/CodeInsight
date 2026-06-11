#include <iostream>
using namespace std;

int days(int year, int month, int day) {
    int mil = 196471;
    int total = 0, max;
    for (int y = 1; y <= year; ++y) {
        for (int m = 1; m <= 10; ++m) {
            max = (y % 3 != 0 && m % 2 == 0) ? 19 : 20;
            for (int d = 1; d <= max; ++d) {
                total++;
                if (y == year && m == month && d == day)
                    return mil - total;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int n, y, m, d;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> y >> m >> d;
        cout << days(y, m, d) << endl;
    }
    return 0;
}