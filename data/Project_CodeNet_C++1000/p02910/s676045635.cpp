#include<algorithm>
#include<cassert>
#include<cmath>
#include<cstdio>
#include<iostream>
#include<map>
#include<numeric>
#include<stack>
#include<string>
#include<deque>
#include<queue>
#include<vector>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;
const double PI = acos(-1);  // PI = 3.141593...

int main() {
    string S;
    cin >> S;

    rep(i, S.size()) {
        if (i%2 == 0 && S[i] == 'L') {
            cout << "No" << endl;
            return 0;
        }
        else if(i%2 == 1 && S[i] == 'R') {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}