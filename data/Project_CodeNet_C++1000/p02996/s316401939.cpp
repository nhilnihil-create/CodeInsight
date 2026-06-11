#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

const int INF = 2e9;

int main(){
    int n;
    cin >> n;
    vector<pii> x(n);
    rep(i,n){
        int a,b;
        cin >> a >> b;
        x[i].first = b;
        x[i].second = a;
    }
    sort(x.begin(),x.end());
    ll now = 0;
    bool ok = true;
    rep(i,n){
        now += x[i].second;
        if(now > x[i].first){
            ok = false;
            break;
        }
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}