/*
      author : nishi5451
      created: 12.08.2020 11:27:35
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int x,y;
    cin >> x >> y;
    int ans=0;
    if(x==1 && y==1) ans+=400000;
    ans +=max(0,(4-x)*100000)+max(0,(4-y)*100000);
    cout << ans << endl;
    return 0;
}
