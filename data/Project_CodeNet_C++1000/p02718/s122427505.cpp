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
    ll N, M;
    vector<ll>A;
    cin >> N >> M;
    string ans = "Yes";
    ld all = 0;
    rep(i,N) {
        ll a;
        cin >>a;
        all += a;
        A.push_back(a);
    }
    sort(A.begin(),A.end(),std::greater<ll>());
    rep(i,M) {
        if (A[i]<(all/(4.0*(ld)M))) {
            ans = "No";
            break;
        }
    }
    cout << ans << endl;
    return 0;
}