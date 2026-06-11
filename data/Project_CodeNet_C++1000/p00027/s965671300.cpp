#include <iostream>
using namespace std;

int main() {
    const char* day[] = {
        "Wednesday", "Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday",
    };
    const int daysPerMonth[] = {
        31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
    };
    int m, d;
    while (true) {
        cin >> m >> d;
        if (m == 0)
            break;

        int daysFromNewYear = d;
        for (int i = 0; i < m - 1; i++) {
            daysFromNewYear += daysPerMonth[i];
        }
        cout << day[daysFromNewYear % 7] << endl;
    }
}