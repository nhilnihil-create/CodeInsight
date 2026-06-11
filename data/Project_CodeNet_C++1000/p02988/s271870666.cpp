#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i,n) cin >> p[i];
    int ans = 0;
    rep(i,n-2){
        vector<int> q;
        rep(j,3) q.push_back(p[i+j]);
        sort(q.begin(), q.end());
        if(p[i+1] == q[1]) ans++;
    }
    cout << ans << endl;
}