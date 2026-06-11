#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rrep(i,n) for(int i=(n)-1; i>=0; i--)
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define RFOR(i,a,b) for(int i=(b-1); i>=(a); i--)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define pb push_back
using ll = long long;
using D = double;
using LD = long double;
using P = pair<int, int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main(){
    int n; cin >> n;
    vector<int> s(1 << n);
    rep(i, (1 << n)) cin >> s[i];
    sort(RALL(s));

    multiset<int> t;
    FOR(i, 1, (1 << n)) t.insert(s[i]);
    vector<int> p;
    p.pb(s[0]);

    rep(i,n){
        vector<int> nex = p;
        for(int v : p){
            auto it = t.lower_bound(v);
            if(it == t.begin()){
                cout << "No" << endl;
                return 0;
            }
            it--;
            nex.pb(*it);
            t.erase(it);
        }
        sort(RALL(nex));
        swap(p, nex);
    }
    cout << "Yes" << endl;
}
