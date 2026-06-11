#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <cstdio>

using namespace std;

typedef long long ll;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)

int main(int argc, char **argv)
{
    int a;
    string s;
    cin >> a >> s;
    if (a >= 3200) cout << s << endl;
    else cout << "red" << endl;
    return 0;
}
