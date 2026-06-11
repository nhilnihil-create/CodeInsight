#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
//ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    int x;
    cin >> x;
    vector<int> a(1e7+1, 0);
    a[1] = 1;
    for (int i = 2; i <= 1e7; ++i) {
        int idx = i;
        if (a[i] != 0) continue; 
        while(1) {
            if (idx >= 1e7) {
                break;
            }
            a[idx] = i;
            idx += i;
        }
    } 
    for (int i = x; i <= 1e7; ++i) {
        if (a[i] == i) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
