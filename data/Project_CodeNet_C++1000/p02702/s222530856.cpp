#include <iostream>
#include <cmath>
#include <algorithm>
#include <climits>
#include <vector>
#include <string>
#include <set>
#include <iomanip>
#include <map>
#define rep(i,n) for (int i=0;i<(n);++i)
#define REP(i,n) for (int i=0;i<=(n);++i)
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int INF = 10000000;

int gcd(int a,int b){return b?gcd(b,a%b):a;}

int main() {
    string s; cin >> s;
    int n = s.size();
    vector<int> val(2019, 0);
    ll fac = 1, cur = 0;

    ++val[cur];
    for(int i = 0; i < n; ++i) {
        ll add = s[n-1-i] - '0';
        cur = (cur + fac * add) % 2019;
        fac = (fac * 10) % 2019;
        ++val[cur];
    }
    ll ans = 0;
    for(int i = 0; i < val.size(); ++i) {
        ans += val[i] * (val[i] - 1) / 2;
    }
    cout << ans << endl;
    
}