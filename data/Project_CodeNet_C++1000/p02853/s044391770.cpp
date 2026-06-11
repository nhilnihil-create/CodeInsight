#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int main(){
    int x,y; cin >> x >> y;
    int ans = 0;
    if(x <= 3){
        ans += (4-x) * 100000;
    }
    if(y <= 3){
        ans += (4-y) * 100000;
    }
    if(x == 1 && x == y) ans += 400000;
    cout << ans << endl;
    return 0;
}