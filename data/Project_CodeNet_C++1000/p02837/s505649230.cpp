#include <bits/stdc++.h>
#define rep(i, n) for(ll i=0;i<n;i++)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (b>a) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const long long INF = 2LL << 60;
using ll = long long;
using P = pair<ll, ll>;
int main(int argc, char const *argv[]){
    int n;
    int ans=-1;
    cin >> n;
    vector<vector<P> > x(n);
    rep(i,n){
        int a;
        cin >> a;
        rep(j,a){
            P p;
            cin >> p.first >> p.second;
            p.first--;
            x[i].push_back(p);
        }
    }
    for(int bit=0;bit<(1<<n);bit++){
        bool flg=true;
        vector<int> t(n, 0);
        for(int i=0;i<n;i++){
            if(bit&(1<<i)){
                t[i]=1;
            }
        }
        for(int i=0;i<n;i++){
            if(!(bit&(1<<i)))continue;
            for(auto p:x[i]) {
                if (t[p.first] == (1 - p.second)) {
                    flg=false;
                    break;
                }
            }
            if(!flg) break;
        }
        if(flg){
            int sum=0;
            for(int i=0;i<n;i++){
                if(bit&(1<<i)){
                    sum++;
                }
            }
            chmax(ans,sum);
        }
    }
    cout << ans << endl;

    return 0;
}


