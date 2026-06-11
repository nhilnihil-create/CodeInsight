#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
#define _ << " " <<
#define all(X) (X).begin(), (X).end()
#define Pii pair<int, int>
#define Pll pair<ll, ll>
#define Tiii tuple<int, int, int>
#define Tlll tuple<ll, ll, ll>
#define PI 3.141592653589793

vector<int> Zalgorithm(string s) {
    int L = 0, R = 0, n = s.size();
    vector<int> z(n);
    for (int i = 1; i < n; i++) {
        if (i > R) {
            L = R = i;
            while (R < n && s[R - L] == s[R]) R++;
            z[i] = R - L;  R--;
        } else {
            int k = i - L;
            if (z[k] < R - i + 1) z[i] = z[k];
            else {
                L = i;
                while (R < n && s[R - L] == s[R]) R++;
                z[i] = R - L;  R--;
            }
        }
    }
    return z;
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    vector<int> tmp(n, -1);
    vector<vector<int>> Z(n, tmp);
    for (int i = 0; i < n; i++) {
        vector<int> y = Zalgorithm(s.substr(i, n));
        for (int j = 1; j < y.size(); j++) {
            Z[i][i + j] = y[j];
        }
    }

    /*
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cerr << Z[i][j] << " ";
        cerr << endl;
    }*/

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ans < Z[i][j] && j - i >= Z[i][j]) ans = Z[i][j];
        }
    }
    cout << ans << endl;    
}
