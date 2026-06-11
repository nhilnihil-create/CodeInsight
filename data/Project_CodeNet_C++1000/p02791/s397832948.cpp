#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    int ans = 1;
    rep(i,n-1){
        int p;
        cin >> p;
        if(m >= p) ans++;
        m = min(m, p);
    }
    cout << ans << endl;
}