/*
      author : nishi5451
      created: 12.08.2020 14:49:20
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int h,w,n;
    cin >> h >> w >> n;
    int ans;
    ans = n/max(h,w);
    if(n%max(h,w) != 0) ans++;
    cout << ans << endl;
    return 0;
}
