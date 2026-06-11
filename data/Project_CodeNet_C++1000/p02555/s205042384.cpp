#include <iostream>
#include <map>
using namespace std;

typedef long long int ll;

const ll mod = 1000000000 + 7;

ll solve(int s, map<int,ll> &memo) {
    if (s == 0) {
        return 1;
    }
    if (memo.find(s) != memo.end()) {
        return memo.find(s)->second;
    }
    ll sum = 0;
    for (int i = 3; i <= s; i++) {
        int next = s - i;
        sum += solve(next, memo);
        sum %= mod;
    }
    memo[s] = sum;
    return sum;
}

int main () {

    int input;
    cin >> input;
    map<int, ll> memo;
    cout << solve(input, memo) << endl;
    return 0;
}