#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define invrep(i,n) for(int i = (int)(n); i > 0; i++)
using ll = long long;

int main() {
    string s, t;
    cin >> s;
    cin >> t;

    string j = "";
    rep(i, s.size()) j += t[i];

    if (s == j) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}