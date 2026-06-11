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
    string s; cin >> s;
    if (s[0] == 'W') {
        cout << 0;
        return 0;
    }
    
    vector<bool> is_L(2*N);
    is_L[0] = true;
    int l_num = 1;
    // cout << 'L';
    FOR(i, 1, 2*N) {
        is_L[i] = (s[i-1]==s[i]) ? !is_L[i-1] : is_L[i-1];
        l_num += is_L[i] ? 1 : 0;
        // cout << (is_L[i] ? 'L' : 'R');
    }
    // cout << endl;
    if (l_num != N) {
        cout << 0;
        return 0;
    }
    
    int l_count = 0;
    int r_count = 0;
    ll result = 1;
    REP(i, 2*N) {
        if (is_L[i]) {
            ++l_count;
        }
        else {
            result *= l_count - r_count;
            result %= MOD;
            ++r_count;
        }
        // cout << i << " " << (is_L[i] ? 'L' : 'R') << " " << l_count << " " << r_count << endl;
    }
    
    FOR(i, 1, N+1) {
        result *= i;
        result %= MOD;
    }
    cout << result;
}