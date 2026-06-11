#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    vector<int> e(n);
    vector<P> p(n);
    rep(i,n){
        int x,y;
        cin >> x >> y;
        s[i]=x-y;
        e[i]=x+y;
    }
    rep(i,n){
        p[i].first=e[i];
        p[i].second=s[i];
    }
    sort(p.begin(),p.end());
    int ans = 0;
    int pr = -pow(10,9)-1;
    rep(i,n){
        if(pr<=p[i].second){
            ++ans;
            pr=p[i].first;
        }
    }
    cout << ans << "\n";
    return 0;
}