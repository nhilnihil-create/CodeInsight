#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main(void){

    int a, b, c, k;
    cin >> a >> b >> c >> k;

    int ans=0;
    if(k <= a){
        ans = k;
    } else {
        k -= a;
        ans += a;
        if(k > b){
            k -= b;
            ans -= k;
        }
    }
    cout << ans << endl;

    return 0;
}