#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
const int mod =1'000'000'007;

int main(){
    int n, m;
    cin >> n >> m;
    vi h(n);
    rep(i,n) cin >> h.at(i);
    vvi list(n);
    rep(i,m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        list.at(a).push_back(b);
        list.at(b).push_back(a);
    }
    int ans = 0;
    rep(i,n){
        bool flag = true;
        for (auto ele : list.at(i)){
            if (h.at(i) <= h.at(ele)) flag = false;
        }
        ans += flag? 1 : 0;
        // if (flag) cout << i << endl;
    }
    cout << ans << endl;
    return 0;
}
