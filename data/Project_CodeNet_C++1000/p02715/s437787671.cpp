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
    int64 solve(int n, int k) {
        vector<int64> dp(k + 1);
        for(int i = k; i; --i) {
            auto& cur = dp[i];
            cur = modpow(k / i, n);
            //cout << "i: " << i << ", k/i: " << k / i << ", val: " << cur << endl;
            for(int j = 2; i * j <= k; ++j) {
                cur = (cur + mod - dp[i * j]) % mod;
            }
        }
        int64 ret = 0;
	    for(int i = 1; i <= k; ++i) {
            ret = (ret + i * dp[i]) % mod;
        }
        return ret;
    }
};

int main() {
    
    int n, k;
    cin >> n >> k;
    
    Solution sol;
    auto ret = sol.solve(n, k);
    cout << ret << endl;
}