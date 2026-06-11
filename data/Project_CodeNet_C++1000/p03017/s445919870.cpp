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

int main() {
    int n; cin >> n;
    int a, b, c, d; cin >> a >> b >> c >> d;
    string s; cin >> s;
    if (c < d) {
        // c < dの場合は b〜dとa〜cに2連続石がなければOK
        FOR(i, b, d-3) {
            if ((s[i] == '#') && (s[i+1] == '#')) {
                cout << "No" << endl;
                return 0;
            }
        }
        FOR(i, a, c-3) {
            if ((s[i] == '#') && (s[i+1] == '#')) {
                cout << "No" << endl;
                return 0;
            }
        }
        cout << "Yes" << endl;
    } else {
        // a < b < d < c
        // まずはbがdまでいけるか確認しつつ、途中で前後が白になるマスがあるか確認
        bool f = false;
        FOR(i, b-1, d-3) {
            if ((s[i] == '#') && (s[i+1] == '#')) {
                cout << "No" << endl;
                return 0;
            }
        }
        // [b, d] を中心として、3連続で白になるマスがあるか確認
        FOR(i, b-1, d-1) {
            if ((s[i-1] == '.') && (s[i] == '.') && (s[i+1] == '.')) {
                cout << "Yes" << endl;
                return 0;
            }
        }
        cout << "No" << endl;
    }
    return 0;
}