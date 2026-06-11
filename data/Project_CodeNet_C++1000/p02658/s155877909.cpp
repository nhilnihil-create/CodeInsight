#include<iostream> 
#include<fstream>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
#include<vector> 
#include<array>
#include<deque>
#include<list>
#include<forward_list>
#include<stack>
#include<queue>
#include<algorithm>
#include<numeric>
#include<iterator>
#include<functional>
#include<map>
#include<unordered_map>
#include<set>
#include<utility>
#include<unordered_set>
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<ll> vll;

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 3;

#define sort_all(v) sort(v.begin(), v.end())
#define fill(a) memset(a, 0, sizeof(a))

#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FOR_REV(i, a ,b) for(int i = a; i >= b; i--)
#define REP(i, n) FOR(i, 0, n)


void test() {
    int n;
    cin >> n;
    vector<int64_t> a(n);
    vector<ld> logarithm;
    for(auto &i : a) {
        cin >> i;
        if(i == 0) {
            cout << 0;
            return;
        }
        logarithm.push_back(log10((ld) i));
    }
    int64_t ans = 1;
    if(accumulate(logarithm.begin(), logarithm.end(), (ld) 0) > 18.1) {
        cout << -1;
        return;
    }
    else {
        for(const auto &i : a) {
            ans *= i;
        }
        if(ans > 1000000000000000000) cout << -1;
        else cout << ans;
    }
}   
 
int main ()     
{
    // int t;
    // cin >> t;
    // while(t--) 
        test();
}
