#include<bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using P = pair<int,int>;
using ll = long long;
using namespace std;

int main(void){
    // Your code here!
    int a,b,c,k;
    cin >> a >> b >> c >> k;
    int ans = 0;
    rep(i, k){
        if(a > 0){
            ++ans;
            --a;
            continue;
        }
        if(b > 0){
            --b;
            continue;
        }
        if(c > 0){
            --ans;
            --c;
            continue;
        }
    }
    cout << ans << endl;
    return 0;
}