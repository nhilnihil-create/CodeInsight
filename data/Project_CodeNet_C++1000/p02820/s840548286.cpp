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
    ll n, k; cin >> n >> k;
    ll r, s, p; cin >> r >> s >> p;
    string t; cin >> t;
    ll res = 0;
    vector<char> prev;
    REP(i, n) {
        char hand = t[i];
        if (i < k) {
            if (hand == 'r') {
                res += p;
                prev.push_back('p');
            } else if (hand == 's') {
                res += r;
                prev.push_back('r');
            } else {
                res += s;
                prev.push_back('s');
            }
        } else {
            if (hand == 'r') {
                if (prev[i-k] != 'p') {
                    res += p;
                    prev.push_back('p');
                } else {
                    if ((i+k < n) && (t[i+k] == 's')) {
                        prev.push_back('s');
                    } else {
                        prev.push_back('r');
                    }
                }
            } else if (hand == 's') {
                if (prev[i-k] != 'r') {
                    res += r;
                    prev.push_back('r');
                } else {
                    if ((i+k < n) && (t[i+k] == 'p')) {
                        prev.push_back('p');
                    } else {
                        prev.push_back('s');
                    }
                }
            } else if (hand == 'p') {
                if (prev[i-k] != 's') {
                    res += s;
                    prev.push_back('s');
                } else {
                    if ((i+k < n) && (t[i+k] == 'r')) {
                        prev.push_back('r');
                    } else {
                        prev.push_back('p');
                    }
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}