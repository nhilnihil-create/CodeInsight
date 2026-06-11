#include <algorithm>
#include <iostream>
#include <cstdio>
#include <map>
#include <numeric>
#include <cmath>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <complex>
#include <string.h>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <iomanip>
#include <sys/time.h>
#include <tuple>
#include <random>
using namespace std;

#define endl '\n'
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define UNIQ(v) (v).erase(unique((v).begin(), (v).end()), (v).end())

string s;

inline bool is_palindrome(string s) {
    return equal(s.begin(), s.end(), s.rbegin());
}

bool solve() {
    int n = s.size();
    return is_palindrome(s) && is_palindrome(s.substr(0, (n-1)/2)) && is_palindrome(s.substr((n+1)/2, (n-1)/2));
}

void input() {
    cin >> s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);

    input();
    cout << (solve()?"Yes":"No") << endl;
}
