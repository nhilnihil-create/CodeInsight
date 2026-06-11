/*
      author  : nishi5451
      created : 15.08.2020 11:42:46
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n;
    cin >> n;
    int index=0;
    int t = n;
    while(t){
        t/=10;
        index++;
    }
    int ans = 0;
    int now = 9;
    for(int i=1; i<=index/2; i++){
        ans += now;
        now *= 100;
    }   
    if(index%2!=0){
        int k = now/9;
        ans += (n-k+1);
    }
    cout  << ans << endl;
    return 0;
}