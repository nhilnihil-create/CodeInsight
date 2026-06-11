#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <unordered_map>
#include <unordered_set>
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
    int solve(int64 n) {
        unordered_set<int64> ret;
        auto div1 = devider(n - 1);
        // for(const auto& i : div1) cout << i << " ";
        // cout << endl;
        for(int i = 1; i < div1.size(); ++i) ret.insert(div1[i]);
        // cout << "show result of div1: \n";
        // for(const auto& rr : ret) cout << rr << " ";
        // cout << endl;
        auto div2 = devider(n);
        //cout << "size div2: " << div2.size() << endl;
        for(int i = 1; i < div2.size(); ++i) {
            int64 temp = n;
            while(temp % div2[i] == 0) temp /= div2[i];
            if(temp % div2[i] == 1) ret.insert(div2[i]);
        }
        // cout << "show result of div2: \n";
        // for(const auto& rr : ret) cout << rr << " ";
        // cout << endl;
        return ret.size();
    }

    vector<int64> devider(int64 n) {
        vector<int64> ret;
        for(int64 i = 1; i * i <= n; ++i) {
            if(n % i == 0) {
                ret.push_back(i);
                if(i * i != n) ret.push_back(n / i);
            }
        }
        sort(begin(ret), end(ret));
        return ret;
    }
};

int main() {
    int64 n;
    cin >> n;
    Solution sol;
    auto ret = sol.solve(n);
    cout << ret << endl;
}