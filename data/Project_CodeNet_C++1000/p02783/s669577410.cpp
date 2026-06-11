/*
      author : nishi5451
      created: 11.08.2020 23:00:35
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int h,a;
    cin >> h >> a;
    int ans = h/a;
    if(h%a!=0) ans++;
    cout << ans << endl;
    return 0;
}