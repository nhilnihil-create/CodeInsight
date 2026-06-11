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
string S;
ll N, M;
vector<string>A;


int main() {
    cin >> N;
    ll ans = 0;
    ans += (N / 500) * 1000;
    ans += ((N % 500) / 5) * 5;
    cout << ans << endl;
    return 0;
}