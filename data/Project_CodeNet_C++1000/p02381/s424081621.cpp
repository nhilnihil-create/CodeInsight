#include <iostream>
#include <cstdio>
#include <array>
#include <cmath>

int main()
{
    using namespace std;
    int n, i;
    array <int, 1000>score;
    double result, sum1, sum2;
    
    while (cin >> n) {
        if (n == 0) break;
        
        sum1 = sum2 = 0;
        for (i = 0; i < n; ++i) {
            cin >> score.at(i);
            sum1 += score.at(i);
            sum2 += score.at(i) * score.at(i);
        }

        result = sqrt(sum2 / n - (sum1 / n ) * (sum1 / n));

        printf("%.8f\n", result);

    }

    return 0;
}
        
        