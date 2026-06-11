#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
using namespace std;

int main(){
    long long h,w;
    cin >> h >> w;
    long long ans = h*w;
    if(ans % 2==1)ans = (ans+1)/2;
    else ans /= 2;
    if(h==1 || w==1)ans =1;
    cout << ans << endl;
}