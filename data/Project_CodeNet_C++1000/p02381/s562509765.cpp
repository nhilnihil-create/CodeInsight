#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <iomanip>
#include <cmath>


using namespace std;
using ull = unsigned long long;


int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;

        vector<int> v(n);

        for (int i = 0; i < n && cin >> v[i]; ++i);

        
        double mean {};
        double sqrSum {};

        for (auto d : v)
        {
            mean += d;
            sqrSum += d * d;
        }
        mean /= n;
        
        double sigma = sqrt(sqrSum / n - mean * mean);

        cout << fixed << setprecision(6) << sigma << endl;


    }




    return 0;
}