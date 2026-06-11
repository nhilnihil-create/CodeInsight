#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <string>
#include <vector>
#include <set>

#define rep(i, x, n) for (int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;

bool cont(vector<int> v, int k, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (v[i] == k)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    int X, N;
    cin >> X >> N;
    vector<int> p(N);
    rep(i, 0, N)
    {
        cin >> p[i];
    }
    rep(i, 0, 100)
    {
        int syo = X - i;
        int dai = X + i;
        if (!cont(p, syo, N))
        {
            cout << syo << endl;
            return 0;
        }
        else if (!cont(p, dai, N))
        {
            cout << dai << endl;
            return 0;
        }
    }
}