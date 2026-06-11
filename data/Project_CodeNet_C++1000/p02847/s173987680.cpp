#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;

int main() {
    string s;
    cin >> s;

    string day[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

    int ans = 7;
    rep(i, 7) {
        if(s == day[i]) {
            cout << ans << endl;
            break;
        }
        ans--;
    }
}