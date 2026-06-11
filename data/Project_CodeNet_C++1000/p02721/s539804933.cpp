#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <unordered_map>
#include <cstring>
#include <algorithm>
#include <set>
#include <climits>
#include <numeric>

//usings
using namespace std;

//type def
typedef long long int64;
typedef pair<int, int> ii;

//consts
const int mod = 1e9 + 7;

//methods
template<typename T>
bool chmax(T& source, const T& compare_to) {
    if(source < compare_to) {
        source = compare_to;
        return true;
    }
    return false;
}

int modpow(int64 base, int n) {
    int64 ret = 1;
    while(n) {
        if(n & 1) ret = ret * base % mod;
        base = base * base % mod;
        n >>= 1;
    }
    return ret;
}

class Solution {
private:
public:
    vector<int> solve(string& s, int n, int k, int cool) {
        vector<int> left(k), right(k); //lf[i] date idx of ith working day
        for(int i = 0, c = 0, day = 0; i < n && day < k; ++i) {
            if(c) {
                --c;
                continue;
            }
            if(s[i] == 'o') {
                left[day++] = i;
                c = cool;
            }
        }
        // cout << "show left: \n";
        // for(int i = 0; i < k; ++i) cout << left[i] << " ";
        // cout << endl;
        for(int i = n - 1, c = 0, day = k - 1; i >= 0 && day >= 0; --i) {
            if(c) {
                --c;
                continue;
            }
            if(s[i] == 'o') {
                right[day--] = i;
                c = cool;
            }
        }
        // cout << "show right: \n";
        // for(int i = 0; i < k; ++i) cout << right[i] << " ";
        // cout << endl;
        vector<int> ret;
        for(int i = 0; i < k; ++i) {
            if(left[i] == right[i]) {
                ret.push_back(left[i] + 1);
            }
        }
        return ret;
    }

    
};

int main() {
    int n, k ,c;
    cin >> n >> k >> c;
    string s;
    cin >> s;
    Solution sol;
    auto ret = sol.solve(s, n, k, c);
    for(const auto& d : ret)
        cout << d << endl;
}