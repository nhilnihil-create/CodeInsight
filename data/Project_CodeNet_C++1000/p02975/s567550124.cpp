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
#include<utility>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define vint(a,n) vint a(n); rep(i, n) cin >> a[i];
#define vll(a,n) vll a(n); rep(i, n) cin >> a[i];
#define ALL(n) begin(n),end(n)
#define RALL(n) rbegin(n),rend(n)
#define MOD (1000000007)
// #define MOD (998244353)
#define INF (2e9)
#define INFL (2e18)

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
using vint=vector<int>;
using vll=vector<ll>;
using vbool=vector<bool>;
template<class T>using arr=vector<vector<T>>;
template<class T>int popcount(T &a){int c=0; rep(i, 8*(int)sizeof(a)){if((a>>i)&1) c++;} return c;}
template<class T>void pr(T x){cout << x << endl;}
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} pr(a[a.size()-1]);}
template<class T>void prarr(arr<T>& a){rep(i, a.size()) if(a[i].empty()) pr(""); else prvec(a[i]);}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main()
{
    int n; cin >> n;
    int z = 0;
    map<int, int> m;
    vint a(n);
    rep(i, n){
        cin >> a[i];
        if(a[i]==0) z++;
        m[a[i]]++;
    }

    if(z==n) {pr("Yes"); return 0;}
    if(n%3!=0) {pr("No"); return 0;}

    if(z > 0){
        if(m.size()>2) pr("No");
        else {
            if(m.size()==2 && n%3==0 && z==n/3) pr("Yes");
            else pr("No");
        }
        return 0;
    }

    if(m.size()!=3) {pr("No"); return 0;}

    vint b, c;
    for(auto p: m) {
        c.push_back(p.second);
        b.push_back(p.first);
    }
    // prvec(b);
    if(c[0]!=c[1] || c[1]!=c[2]) {pr("No"); return 0;}
    if(((b[0]^b[1])^b[2])==0) {pr("Yes");}
    else pr("No");
    // pr(1^3^5);
    return 0;}