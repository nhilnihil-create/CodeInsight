#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
const ll mod = 1e9+7;
int inf = 1000000000; //10e9
 
int main() {
    
    ll H, W;
    cin >> H >> W;
    ll ans = 0;

    if(H==1 || W==1){
        ans = 1;
    }else{
        ans = (H*W+1)/2;
    }

    cout << ans << endl;
}