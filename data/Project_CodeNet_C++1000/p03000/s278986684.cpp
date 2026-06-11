#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n, x;
    cin >> n >> x;
    int d = 0, ans = 1;
    rep(i,n){
        int l;
        cin >> l;
        d += l;
        if(d <= x) ans++;
    }
    cout << ans << endl;
}