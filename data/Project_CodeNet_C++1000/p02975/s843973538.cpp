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
    ll n; cin >> n;
    ll a[100001]; INITA(a, 0, 100000, 0);
    ll tmp;
    map<ll, ll> m;
    REP(i, n) {
        cin >> tmp;
        if (m.find(tmp) == m.end()) {
            m[tmp] = 0;
        }
        m[tmp]++;
    }

    if ((m.size() == 1) && (m.find(0) != m.end())) {
        // 0のみの場合はOK
        cout << "Yes" << endl;
    } else if ((m.size() == 2) && (m.find(0) != m.end()) && (n == 3 * m[0])) {
        // 0の個数をaとして、それ以外の値が1種類で2a個存在すればOK
        cout << "Yes" << endl;
    } else if (m.size() > 3) {
        // 数字の異なり数が3を超えると成り立たない
        cout << "No" << endl;
    } else if (m.size() == 3) {
        // 3種類それぞれの個数が一致していて、かつそれぞれのxor関係が成り立てばOK
        vector<ll> v;
        set<ll> st;
        for (auto e: m) {
            v.push_back(e.first);
            st.insert(e.second);
        }
        if (st.size() != 1) {
            cout << "No" << endl;
        } else {
            if ((v[0] ^ v[1]) == v[2] && (v[0] ^ v[2]) == v[1] && (v[1] ^ v[2]) == v[0]) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    } else {
        cout << "No" << endl;
    }
    return 0;
}