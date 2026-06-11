#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <sstream>
#include <algorithm>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <climits>
#include <bitset>
#include <functional>
#include <numeric>
#include <ctime>
#include <cassert>
#include <cstring>
#include <fstream>
#include <iomanip>

using namespace std;

#define FOR(i, a, b) for(int (i)=(a);(i)<(b);(i)++)
#define IFOR(i, a, b) for(int (i)=(a);(i)<=(b);(i)++)
#define RFOR(i, a, b) for(int (i)=(a);(i)>=(b);(i)--)
#define REP(i, n) FOR((i), 0, (n))

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;


int getketa(int x){
    int cnt = 0;
    while(x>0){
        cnt++;
        x /= 10;
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;

    ll memo[10][10] = {0};

    ll ans1 = 0, ans2 = 0;
    IFOR(a, 1, n){
        int tail = a % 10;
        int tmp = a;
        while(tmp>=10) tmp /= 10;
        int head = tmp;
        ans1 += memo[tail][head];

        if(head == tail){
            ans2++;
        }
        memo[head][tail]++;
    }
    ll ans = ans1*2+ans2;

    cout << ans << endl;

    return 0;
}