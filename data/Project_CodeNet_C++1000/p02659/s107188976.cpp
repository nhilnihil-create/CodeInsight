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
    ll a, b;
    int f;
    scanf("%lld %lld.%d", &a, &b, &f);
    b = b * 100 + f;
    ll ans = (a * b) / 100;
    cout << ans;
}   
 
int main ()     
{
    // int t;
    // cin >> t;
    // while(t--) 
        test();
}
