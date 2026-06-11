#include <iostream>
#include <cstdlib>
#include <vector>
#include <stack>
#include <string>
#include <climits>
#include <algorithm>
#include <functional>
#include <string.h>
#include <numeric>
#include <math.h>

#define LOOP(N) for(int i=0; i<(N); ++i)
#define REP(i, N) for(int i=0; i<(N); ++i)
#define FOR(i, start, end) for(int i=(start); i<(end); ++i)
#define ALL(a) (a).begin(),(a).end()

using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using Graph = vector< vector<int> >;

const ll MOD = 1000000007;

void sayYes() {cout << "Yes" << endl;}
void sayNo() {cout << "No" << endl;}


int main() {
    int N; cin >> N;
    char s[1000001] = {0,}; cin >> s;
    if (s[0] == 'W') {
        cout << 0;
        return 0;
    }
    
    bool is_L = true;
    int l_num = 1;
    int factor = 1;
    ll result = 1;
    FOR(i, 1, 2*N) {
        is_L = (s[i-1]==s[i]) ? !is_L : is_L;
        if (is_L) {
            ++l_num;
            ++factor;
        }
        else {
            result = result * factor % MOD;
            --factor;
        }
        // cout << i << " " << (is_L ? 'L' : 'R') << " " << l_count << " " << r_count << endl;
    }
    if (l_num != N) {
        cout << 0;
        return 0;
    }

    FOR(i, 1, N) {
        result = result * i % MOD;
    }
    cout << result * N % MOD;
}