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
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define vint(a,n) vint a(n); rep(i, n) cin >> a[i];
#define ALL(n) begin(n),end(n)
#define RALL(n) rbegin(n),rend(n)
#define MOD (1000000007)
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
    vint(a, n);

    int neg=0, pos=0;
    rep(i, n){
        if(a[i]<0) neg++;
        else pos++;
    }

    sort(ALL(a));

    vint v, w;

    if(neg==0){
        priority_queue<int, vector<int>, greater<int>> p;
        rep(i, n) p.push(a[i]);
        while(p.size()>1){
            int s, t;
            s = p.top(); p.pop();
            t = p.top(); p.pop();
            if(p.empty()) swap(s, t);
            v.push_back(s); w.push_back(t);
            p.push(s-t);
        }
        pr(p.top());
        rep(i, v.size()){
            cout << v[i] << " " << w[i] << endl;
        }
        return 0;
    }else if(pos==0){
        priority_queue<int> p;
        rep(i, n) p.push(a[i]);
        while(p.size()>1){
            int s, t;
            s = p.top(); p.pop();
            t = p.top(); p.pop();
            v.push_back(s); w.push_back(t);
            p.push(s-t);
        }
        pr(p.top());
        rep(i, v.size()){
            cout << v[i] << " " << w[i] << endl;
        }
        return 0;
    }

    priority_queue<int> p, q;
    rep(i, n){
        if(i<neg) q.push(a[i]);
        else p.push(a[i]);
    }

    while(p.size()>1){
        int s, t;
        s = q.top(); q.pop();
        t = p.top(); p.pop();
        swap(s, t);
        v.push_back(t); w.push_back(s);
        q.push(t - s);
    }

    while(!q.empty()){
        int s, t;
        s = q.top(); q.pop();
        t = p.top(); p.pop();
        v.push_back(t); w.push_back(s);
        p.push(t - s);
    }

    pr(p.top());
    rep(i, v.size()){
        cout << v[i] << " " << w[i] << endl;
    }
    return 0;}