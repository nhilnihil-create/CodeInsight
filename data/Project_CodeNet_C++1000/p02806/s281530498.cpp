#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <tuple>
#include <cstring>
#include <map>
#include <iomanip>
#include <ctime>
#include <complex>
#include <cassert>
#include <climits>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define _ << " " <<
#define all(X) (X).begin(), (X).end()
#define len(X) (X).size()
#define Pii pair<int, int>
#define Pll pair<ll, ll>
#define Tiii tuple<int, int, int>
#define Tlll tuple<ll, ll, ll>

int main() {
    int n;
    cin >> n;
    string s[n];
    int t[n], sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> t[i];
        sum += t[i];
    }
    string x;
    cin >> x;
    for (int i = 0; i < n; i++) {
        sum -= t[i];
        if (s[i] == x) {
            cout << sum << endl;
            return 0;
        }
    }
}
