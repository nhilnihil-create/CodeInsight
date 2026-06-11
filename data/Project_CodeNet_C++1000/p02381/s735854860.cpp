#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    double second_moment, first_moment, score, std;

    while (cin >> n)
    {
        if (n == 0)
        {
            break;
        }
        first_moment = 0.0;
        second_moment = 0.0;
        for (int i = 0; i < n; ++i)
        {
            cin >> score;
            first_moment += score;
            second_moment += score * score;
        }
        first_moment /= n;
        second_moment /= n;
        std = sqrt(second_moment - first_moment * first_moment);
        printf("%10.8f\n", std);
    }
}
