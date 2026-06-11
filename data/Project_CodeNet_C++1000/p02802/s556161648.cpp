#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <map>
#include <bitset>
using namespace std;

#define INF 1e9
#define LLINF 1e18
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int gcd(int a, int b) {
    if(a % b == 0) {
        return b;
    }
    else {
        return(gcd(b, a % b));
    }
}


int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    vector<string> b(m);
    rep(i, m) {
        cin >> a.at(i) >> b.at(i);
    }
    vector<bool> acb(n, false);
    vector<int> c(n);
    int ac = 0, wa = 0;
    rep(i, m) {
        if (!acb.at(a.at(i) - 1) && b.at(i) == "AC") {
            acb.at(a.at(i) - 1) = true;
            ac++;
        }
        else if (!acb.at(a.at(i) - 1) && b.at(i) == "WA") {
            wa++;
        }
        if (b.at(i) == "WA") {
            c.at(a.at(i) - 1)++;
        }
    }
    rep(i, n) {
        if (!acb.at(i)) {
            wa -= c.at(i);
        }
    }
    cout << ac << " " << wa << endl;
}