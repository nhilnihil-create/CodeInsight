#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

lli h, w, a, b;

int main(void){
    cin >> h >> w >> a >> b;
    vector<lli> r(h), c(w);
    vector<string> ans(h);
    rep(i, h){
        if(i < b){
            string t(a, '0');
            string u(w-a, '1');
            ans[i] = t+u;
        }else{
            string t(a, '1');
            string u(w-a, '0');
            ans[i] = t+u;
        }
    }
    rep(i, h) cout << ans[i] << endl;
    return 0;
}
