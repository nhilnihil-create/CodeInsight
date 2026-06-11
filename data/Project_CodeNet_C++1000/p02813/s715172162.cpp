
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

#define coutv(v) for (int i = 0; i < (v).size(); ++i) cout << v[i] << ' '; cout << endl;
#define coutvv(v) for (int i = 0; i < (v).size(); ++i) {for (int j = 0; j < (v[i]).size(); ++j) cout << v[i][j] << ' '; cout << endl;}
#define debugv(v) {for (int i = 0; i < (v).size(); ++i) cerr << v[i] << ' '; cerr << endl;}
#define debugvv(v) {for (int i = 0; i < (v).size(); ++i) {for (int j = 0; j < (v[i]).size(); ++j) cerr << v[i][j] << ' '; cerr << endl;}}
#define TC int TESTCASE; cin >> TESTCASE; while (TESTCASE--)
typedef long long ll;


int main() {
    vector<int> fact(20);
    fact[0] = 0;
    fact[1] = 1;
    for (int i = 2; i < 15; i++) {
        fact[i] = fact[i-1] * (i);
    }
    int n; cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    int res = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for(int j = 0; j < p[i] - 1; j++) {
            if (a[j] == 0) {
                cnt += 1;
            }
        }
        a[p[i] - 1] = 1;
        res += fact[n-(i+1)] * cnt;
    }
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    a.clear();
    a.resize(n);
    int res1 = 0;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for(int j = 0; j < (p[i] - 1); j++) {
            if (a[j] == 0) {
                cnt += 1;
            }
        }
        a[p[i] - 1] = 1;
        res1 += fact[n-(i+1)] * cnt;
    }
    cout << abs(res - res1) << endl;
}

