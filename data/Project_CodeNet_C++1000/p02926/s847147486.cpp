#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;
using Engine = tuple<int, int, double>;

int main()
{
    int n;
    vector<Engine> engines;
    cin >> n;
    int x, y;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        cin >> y;
        engines.emplace_back(x, y, atan2(y, x));
    }
    sort(engines.begin(), engines.end(), [](const Engine& x, const Engine& y) { return get<2>(x) < get<2>(y); });

    double maxLength = 0;
    for (int begin = 0; begin < n; ++begin)
    {
        for (int count = 1; count <= n; ++count)
        {
            long long sumX = 0, sumY = 0;
            for (int i = 0; i < count; ++i)
            {
                Engine engine = engines[(begin + i) % n];
                sumX += get<0>(engine);
                sumY += get<1>(engine);
            }
            double length = sqrt(sumX * sumX + sumY * sumY);
            maxLength = max(maxLength, length);
        }
    }
    cout << setprecision(15) << maxLength << endl;

    return 0;
}
