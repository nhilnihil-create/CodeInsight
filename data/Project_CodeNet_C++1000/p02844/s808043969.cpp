#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD (1000000007)
#define INF (1e9)
#define INFL (1e18)

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
template<class T>using arr=vector<vector<T>>;
template<class T>void pr(T x){cout << x << endl;}
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} pr(a[a.size()-1]);}
template<class T>void prarr(arr<T>& a){rep(i, a.size()) if(a[i].empty()) pr(""); else prvec(a[i]);}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main()
{
    int n; string s; cin >> n >> s;
    int ans=0;
    rep(i, 1000){
        int a[3];
        if(i<100) a[0] = 0;
        else a[0] = i/100;
        if(i<10) a[1] = 0;
        else a[1] = (i%100)/10;
        a[2] = i%10;
        int ai = 0;
        // printf("%d%d%d\n", a[0], a[1], a[2]);
        rep(j, n){
            if(a[ai] == s[j]-'0'){
                ai++;
                if(ai==3) break;
            }
        }
        if(ai==3) {
            // pr(i);
            ans++;
        }
    }
    pr(ans);
    return 0;}