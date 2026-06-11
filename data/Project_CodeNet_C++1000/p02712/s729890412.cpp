#include <iostream>
#include <iomanip>
#include<vector>
#include <algorithm>
#include <queue>
#include<string>
#include <map>
#include <cmath>
#include <deque>
#include <list>
#include <stack>
#include <queue>
#include <utility>
#include <set>
#include <bitset>
typedef long long ll;
typedef long double ld;
#define PI  3.14159265358979323846

#define REP(i,s,n)for(ll i=s;i<(n);++i)
#define rep(i,n) REP(i,0,n)
using namespace std;

int main() {
    ll N;
    cin >> N;
    ll ans = 0;
    REP(i,1,N+1) {
        if (i%3==0&&i%5==0);
        else if (i % 3 == 0);
        else if (i % 5 == 0);
        else {
            ans += i;
        }
    }
    cout << ans << endl;
    return 0;
}