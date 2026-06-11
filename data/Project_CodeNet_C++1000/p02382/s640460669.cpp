#include <bits/stdc++.h>
using namespace std;

double dist_Minkowski_finite(vector<double>, vector<double>, int);
double dist_Minkowski_infinite(vector<double>, vector<double>);

int main()
{
    vector<double> v1, v2;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        double temp;
        cin >> temp;
        v1.push_back(temp);
    }

    for (int i = 0; i < n; i++)
    {
        double temp;
        cin >> temp;
        v2.push_back(temp);
    }

    cout << fixed << setprecision(cout.precision()) << dist_Minkowski_finite(v1, v2, 1) << endl;
    cout << fixed << setprecision(cout.precision()) << dist_Minkowski_finite(v1, v2, 2) << endl;
    cout << fixed << setprecision(cout.precision()) << dist_Minkowski_finite(v1, v2, 3) << endl;
    cout << fixed << setprecision(cout.precision()) << dist_Minkowski_infinite(v1, v2) << endl;

    return 0;
}

double dist_Minkowski_finite(vector<double> v1, vector<double> v2, int p)
{
    double res = 0.0;
    for (int i = 0; i < (int) v1.size(); i++)
    {
        res += pow(abs(v1[i] - v2[i]), p);
    }
    return pow(res, 1.0 / p);
}

double dist_Minkowski_infinite(vector<double> v1, vector<double> v2)
{
    vector<double> res(v1.size(), 0.0);
    for (int i = 0; i < (int) v1.size(); i++)
    {
        res[i] = abs(v1[i] - v2[i]);
    }

    return *max_element(res.begin(), res.end());
}
