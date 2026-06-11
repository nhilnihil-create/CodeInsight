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
    const int mod = 1e9 + 7;
    vector<int> v1(13, 0), v2(13, 0);
    v1[0] = 1;
    for (int i = 0; i < s.size(); i++) {
        v2 = vector<int>(13, 0);
        if (s[i] == '?') {
            for (int k = 0; k <= 9; k++) {
                for (int j = 0; j < 13; j++) {
                    v2[(j * 10 + k) % 13] += v1[j];
                    v2[(j * 10 + k) % 13] %= mod;    
                }
            }
        } else {
            int num = s[i] - '0';
            for (int j = 0; j < 13; j++) {
                v2[(j * 10 + num) % 13] += v1[j];
                v2[(j * 10 + num) % 13] %= mod;
            }
        }
        v1 = v2;
    }
    cout << v1[5] % mod << endl;
}
