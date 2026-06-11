#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <cassert>
#include <random>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
typedef long long int ll;
const ll INF = 10000000000;
const double PI = acos(-1);
const ll mod = 1000000007;

int n, d;

double CalcDist(vector<int> a, vector<int>b) {
    int sum = 0;
    rep(i, d) {
        sum += (a[i] - b[i]) * (a[i] - b[i]);
    }
    return sqrt((double)sum);
}

bool IsInteger(double x) {
    return floor(x) == x;
}

int main()
{
    cin >> n >> d;
    vector<vector<int>> x(n);
    rep(i, n) rep(j, d) {
        int tmp;
        cin >> tmp;
        x[i].push_back(tmp);
    }

    int ans = 0;
    rep(i, n) {
        for (int j = i + 1; j < n; j++) {
            double dist = CalcDist(x[i], x[j]);
            if (IsInteger(dist)) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
