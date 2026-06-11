#include <bits/stdc++.h>
#include <vector> 
# include <cstdint>
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define RFOR(i,l,r) for(int i=(l);i>=(int)(r);i--)
#define rep(i,n)  FOR(i,0,n)
#define rrep(i,n)  RFOR(i,n-1,0)

#define int long long
using namespace std;
const int MX = 1e6;
const int inf = 1e9;

vector<int> ra(MX,0);
vector<int> par(MX,0);

vector<int> ra2(MX,0);
vector<int> par2(MX,0);

using P = pair<int, int>;
int find(int x) {
    if(par[x] == x) {
        return x;
    } else {
        return par[x] = find(par[x]);
    }
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(x==y) return;
    if(ra[x]<ra[y]) {
        par[x] = y;
    }else {
        par[y] = x;
        if(ra[x]==ra[y]) {
            ra[x]++;
            
        }
    }
}

bool same(int x, int y) {
    return find(x) == find(y);
}

void init(int n) {
    for(int i = 0; i < n; i++) {
        par[i] = i;
        ra[i] = 0;

    }
}

int a[MX];
int c[10][1000];

signed main(){
    string s;
    cin >> s;
    rep(i, s.length()) {
        if(i%2==0) {
            if(s[i]=='L') {
                cout << "No" << endl;
                return 0;
            }
        }else {
            if(s[i]=='R') {
                cout << "No" << endl;
                return 0;
            }
        }
        
    }


    cout << "Yes" << endl;

    return 0;

}

