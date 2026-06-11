#include <bits/stdc++.h>
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;

int main(){
    int h,w,n;
    cin >> h >> w >> n;
    int t;
    t=max(h,w);
    int ans;
    ans = n/t;
    if(n%t!=0)ans++;
    cout << ans << endl;
}