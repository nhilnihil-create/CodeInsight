#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using Graph = vector<vector<int>>;
using ll = long long;
using p = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= 10; ++i)
    {
        int money = i * 1000;
        int charge = money - n;
        if (charge < 0)
        {
            continue;
        }
        cout << charge << endl;
        return 0;
    }
    return 0;
}