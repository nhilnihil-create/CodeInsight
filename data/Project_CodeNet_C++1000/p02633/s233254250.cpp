#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define rep(i,n) for(ll i=0;i<(ll)n;i++)


int main(){
    int x; cin >> x;

    int r = 1, y = 360;
    int res = 0;
    while(r){
        r = y%x;
        res+=(y/x);
        y = 360 + r;
    }
    cout << res << endl;
}