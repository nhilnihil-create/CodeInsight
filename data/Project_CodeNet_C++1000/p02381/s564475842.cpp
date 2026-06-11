#include <bits/stdc++.h>
using namespace std;

double calcStdDev(vector<double>);

int main()
{
    int n;

    while (1)
    {
        cin >> n;
        if (n == 0)
            break;

        vector<double> s(n, 0.0);
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
        }

        cout << fixed << setprecision(cout.precision()) << calcStdDev(s) << endl;
    }

    return 0;
}

double calcStdDev(vector<double> s)
{
    double mean = 0.0;
    for (long unsigned int i = 0; i < s.size(); i++)
    {
        mean += s[i];
    }
    mean /= (double)s.size();

    double res = 0.0;
    for (long unsigned int i = 0; i < s.size(); i++)
    {
        res += pow(abs(s[i] - mean), 2);
    }
    res /= (double)s.size();

    return sqrt(res);
}
