#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void){
    long n,c[10][10]={},ans=0;
    cin >> n;
    rep(i,10)rep(j,10){
        for(int k=1;k<=n;k++){
            if(k%10==j&&to_string(k)[0]=='0'+i) c[i][j]++;
        }
    }
    rep(i,10)rep(j,10) ans += c[i][j]*c[j][i];
    cout << ans << endl;
}
