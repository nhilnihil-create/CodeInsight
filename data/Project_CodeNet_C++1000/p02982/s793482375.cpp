#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int sqd(vector<int> a, vector<int> b, int d)
{
    int res = 0;
    for (int i = 0; i < d; i++)
    {
        res += pow(a[i] - b[i], 2);
    }
    return res;
}

bool sq_check(int n)
{
    int sqr = sqrt(n);
    if (pow(sqr, 2) == n)
        return true;
    else
        return false;
}

int main()
{
    int n, d;
    cin >> n >> d;
    vector<vector<int>> x(n, vector<int>(d));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < d; j++)
        {
            cin >> x[i][j];
        }
    }

    int res = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int dist = sqd(x[i], x[j], d);
            if (sq_check(dist) == true)
                res++;
        }
    }

    cout << res << endl;
}