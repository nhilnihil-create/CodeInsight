#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <set>
// #include <unordered_set>
#include <map>
// #include <unordered_map>
#include <cmath>
#include <deque>
#include <queue>
#include <string>
#include <cstring>
#include <stack>

using namespace std;
typedef long long ll;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (int i = a; i < b; i++)
#define V vector

int n, m;


int main() {
    cin >> n >> m;
    if(n%2 == 1) {
        REP(i, 1, m+1) {
            cout << i << " " << n+1-i << "\n";
        }
    } else {
        REP(i, 1, min(m+1, (int)n/4+1)) {
            cout << i << " " << (n>>1)+1-i << "\n";
        }
        if(m > n/4) {
            REP(i, 1, m+1 - (int)n/4) cout << i + int(n/2) << " " << n-i << "\n";
        }
    }

    return 0;
}
/*

 */