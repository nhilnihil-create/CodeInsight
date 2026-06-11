#include<algorithm>
#include<bitset>
#include<cmath>
#include<complex>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<iterator>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>
using namespace std;
typedef long long ll;
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) (x).begin(),(x).end()
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define D()
#define INF 1000000000000
#define MOD 10000007
#define MAXR 100000
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define INITA(a,i,j,v) for(ll k=i;k<=j;k++){a[k]=v;}

bool is_triangle(int a, int b, int c) {
    if ((a < b + c) && (b < a + c) && (c < a + b)) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int n; cin >> n;
    vector<int> l;
    int tmp;
    REP(i, n) {
        cin >> tmp;
        l.push_back(tmp);
    }
    sort(ALL(l));

    ll res = 0;
    FOR(ai, 0, n-3) {
        FOR(bi, ai+1, n-2) {
            FOR(ci, bi+1, n-1) {
                if (is_triangle(l[ai], l[bi], l[ci])) {
                    res++;
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}