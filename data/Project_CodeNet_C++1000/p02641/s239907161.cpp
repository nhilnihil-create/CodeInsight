#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
const int mod =1'000'000'007;

int main(){
    int x, n;
    cin >> x >> n;
    vi p(102,1);
    rep(i,n){
        int pi;
        cin >> pi;
        p.at(pi)--;
    }

    int min = 100;
    int ans;
    REP(i,0,102){
        if (p.at(i) == 0) continue;
        int res;
        res = abs(i - x);
        if (res < min){
            ans = i;
            min = res;
        }
    }
    cout << ans << endl;
    return 0;
}
