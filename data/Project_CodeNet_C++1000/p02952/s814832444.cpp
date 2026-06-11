#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
/////////////////////////////////
int main(){
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n;++i){
        if(i<10)
            ans++;
        if(i>99 && i<1000)
            ans++;
        if(i>9999 && i!=100000)
            ans++;
    }
    cout << ans << endl;
}