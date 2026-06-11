#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
int main(){
    int h,w,a,b; cin >> h >> w >> a >> b;
    rep(i,h){
        rep(j,w) cout << ((i<b && j<a) || (i>=b && j>=a) ? 0 : 1);
        cout << endl;
    }
}