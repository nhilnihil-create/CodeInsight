#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
    int n;
    double ave = 0.0, sum = 0.0, score[1001];
    while (cin >> n && n != 0)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> score[i];
            ave += score[i];
        }
        ave /= n;
        for (int i = 0; i < n; i++)
        {
            sum += pow(score[i] - ave, 2);
        }
        cout << fixed << setprecision(8) << sqrt(sum / n) << endl;;
        ave = 0;
        sum = 0;
    }

    return 0;
}
