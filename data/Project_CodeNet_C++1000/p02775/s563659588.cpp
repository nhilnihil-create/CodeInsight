#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using bint = boost::multiprecision::cpp_int;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define repSE(i,s,n) for (int i = (s); i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MAX_LEN = 1000000;

int main()
{
    string s;
    cin >> s;
    int ls = s.length();
    int c[MAX_LEN][2];
    int s0 = s[0] - '0';
    c[0][0] = min(s0, 11 - s0);
    c[0][1] = min(s0 + 1, 10 - s0);
    repSE(i, 1, ls) {
        int si = s[i] - '0';
        c[i][0] = min(c[i-1][0] + si, c[i-1][1] + 10 - si);
        c[i][1] = min(c[i-1][0] + si + 1, c[i-1][1] + 9 - si);
    }
    cout << c[ls-1][0] << endl;
    return 0;
}
