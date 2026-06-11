#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <functional>

using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i, n) for(int i = 0; i < n; i++)


int main() {
    string s;
    cin >> s;

    if (s == "hi" || s == "hihi" || s == "hihihi" || s == "hihihihi" || s == "hihihihihi") {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
