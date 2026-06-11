#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int main() {
    string s;
    cin >> s;
    int last = 1;
    int res = 1;
    int n = s.size();
    int index = 1;
    while (index < n) {
        if (last == 2) {
            last = 1;
            res++;
            index++;
        } else {
            if (s[index] != s[index - 1]) {
                res++;
                index++;
            } else {
                if (index != n - 1) res++;
                index += 2;
                last = 2;
            }
        }
    }
    cout << res << endl;
}


