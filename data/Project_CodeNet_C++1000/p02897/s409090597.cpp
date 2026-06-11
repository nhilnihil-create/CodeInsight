#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <map>           // sorted map so O(logn)
#include <unordered_map> // O(1)
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main()
{
    int n;
    cin >> n;
    double t = (n / 2) + (n % 2);
    cout << fixed << setprecision(10) << t / n << endl;
}
