#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <map>
#include <cmath>
#include <cstring>

#define fi first
#define se second
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for (int i = 1; i < (n); ++i)
#define drep(i,n) for (int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define all(x) (x).begin(), (x).end()
#define maxs(x,y) (x = max(x,y))
#define mins(x,y) (x = min(x,y))
#define pb push_back
#define sz(x) (int)(x).size()
#define PQ(T) priority_queue<T, v(T), greater<T> >

using namespace std;
typedef long long ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int,int> P;

const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;

const int mod = 1000000007;

int main() {
    ll t1, t2, a1, a2, b1, b2;
    cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
    a1 *= t1;
    a2 *= t2;
    b1 *= t1;
    b2 *= t2;
    if (a1 < b1) {
        swap(a1,b1);
        swap(a2,b2);
    }
    ll d1 = a1 - b1;
    ll d2 = b1+b2-a1-a2;

    if (a1+a2>(b1+b2)) {
        cout << 0 << endl;
        return 0;
    }
    if (d2>d1) {
        cout << 1 << endl;
        return 0;
    }
    if (a1+a2==b1+b2) {
        cout << "infinity" << endl;
        return 0;
    }

    ll num = (d1 +(d2-1)) / d2;
    num *= 2;
    --num;
    if (d1%d2==0) num += 1;
    //num += 1;
    //cout << "d1: " << d1 << " d2: " << d2 << endl;
    cout << num << endl;
    return 0;
}
