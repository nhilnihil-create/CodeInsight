#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define INF 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main()
{
    int x;
    int c = 0;
    string s;
    string abc = "ABC";
    cin >> x;
    cin >> s;
    int pos = s.find(abc);

    while (pos != string::npos)
    {
        c++;
        pos = s.find(abc, pos + 3);
    }

    cout << c << endl;
}