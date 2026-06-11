#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <list>
#include <utility>
#include <tuple>
#include <cstdio>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <cmath>
#define _GLIBCXX_DEBUG
using namespace std;
const long long INF = 1LL << 60;
typedef long long ll;
int main() {
    ll H;
    cin >> H;
    ll hit=0;
    ll cnt = 1;
    while(H>1){
        H = H / 2;
        hit = hit + cnt;
        cnt = cnt * 2;
    }
    ll ans = hit + cnt;
    cout << ans << endl;
}