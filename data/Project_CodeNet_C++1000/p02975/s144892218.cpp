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
const int inf = 1e13;
const int mod = 1e9+7;
#define ll long long

signed main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    set<int> s;
    rep(i,n) {
        s.insert(a[i]);
    }
    if(s.size()==1) {
        for(auto m:s) {
            if(m==0) {
                cout << "Yes" << endl;
                return 0;
            }else {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    if(s.size()==2) {
        bool f = false;
        for(auto m:s) {
            if(m==0) f = true;
        }
        if(!f) cout << "No" << endl;
        else {
            int cnt = 0;
            rep(i,n) {
                if(a[i]==0) cnt++;
            }
            if(n%3==0 && cnt==n/3) {
                cout << "Yes" << endl;
            }else cout << "No" << endl;
        }
        return 0;
    }
    if(n%3==0 && s.size()==3) {
        vector<int> b;
        for(auto m:s){
            b.push_back(m);
        }
        vector<int> c(3,0);
        rep(i,n) {
            if(b[0]==a[i]) c[0]++;
            if(b[1]==a[i]) c[1]++;
            if(b[2]==a[i]) c[2]++;
        }
        if((b[0]^b[1]^b[2])==0 && c[0]==n/3&& c[1]==n/3&& c[2]==n/3) {
            cout << "Yes" << endl;
            return 0;
        } 
    } 
    cout << "No" << endl;
    
    return 0;
}

