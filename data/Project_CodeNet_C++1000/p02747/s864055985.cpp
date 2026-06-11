#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;

typedef long long LL;

string str;

int main() {
    cin >> str;
    bool flag = true;
    for (int i = 0;i < str.size();i ++) {
        if ((i % 2 == 0 && str[i] != 'h') || (i % 2 == 1 && str[i] != 'i')) {
            flag = false;
            break;
        }
    }
    if (flag && str.size() % 2 == 0 && str.size() != 0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}