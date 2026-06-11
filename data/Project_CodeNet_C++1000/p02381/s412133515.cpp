#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    cout << fixed;
    cout << setprecision(10);

    while (true) {
        int n;
        cin >> n;

        if (n == 0)
            break;

        vector<int> score;
        int sum = 0;

        for (int i = 0; i < n; i++) {
            int s;
            cin >> s;

            score.push_back(s);
            sum += s;
        }

        double mean = (double) sum / n;

        double tmp = 0;
        for (auto s : score) {
            tmp += pow(s - mean, 2);
        }

        cout << sqrt(tmp / n) << endl;
    }
    return 0;
}