#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD 1000000007
 
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
template<class T>void print(T x){cout << x << endl;}
template<class T>void printvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} cout << a[a.size()-1] << endl;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
 
int main()
{
    int x, y, a, b, c; cin >> x >> y >> a >> b >> c;
    vector<int> p(a), q(b), r(c);
    rep(i, a) cin >> p[i];
    rep(i, b) cin >> q[i];
    rep(i, c) cin >> r[i];

    sort(ALL(p), greater<int>());sort(ALL(q), greater<int>());sort(ALL(r), greater<int>());
    // printvec(p);printvec(q);printvec(r);
    vector<int> eat(x+y);
    int pi=0, qi=0, ei=0;
    while(ei<x+y){
        if(qi==y || (pi<x && p[pi]>q[qi])){
            eat[ei] = p[pi];
            pi++;
        }else{
            eat[ei] = q[qi];
            qi++;
        }
        ei++;
    }
    // printvec(eat);
    int ri=0, tail=x+y-1;
    while(r[ri] > eat[tail]){
        eat[tail] = r[ri];
        tail--;
        ri++;
    }
    // printvec(eat);
    ll ans=0;
    rep(i, x+y) ans+=(ll)eat[i];
    
    print(ans);
    return 0;
}