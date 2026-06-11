#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;

int
main(int argc, const char *argv[])
{
    int n;
    while (cin >> n && n) {
        double sum = 0;
        vector<int> vi;
        for (int i = 0; i < n; ++i) {
            int s;
            cin >> s;
            sum += s;
            vi.push_back(s);
        }
        double m = sum / n;
        double v = 0;
        for (auto & s : vi) {
            v += (s - m) * (s - m); 
        }
        printf("%.5lf\n", sqrt(v / n));
    }

    return 0;
}