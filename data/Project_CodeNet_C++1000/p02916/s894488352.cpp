/*
      author  : nishi5451
      created : 15.08.2020 12:28:20
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n;
    cin >> n;
    vector<int> a(n+1),b(n+1),c(n);
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=1; i<=n; i++){
        cin >> b[i];
    }
    for(int i=1; i<=n-1; i++){
        cin >> c[i];
    }
    int ans = 0;
    int pre = -2;
    for(int i=1; i<=n; i++){
        ans += b[a[i]];
        if(pre+1==a[i]){
            ans += c[pre];
        }
        pre = a[i];
    }
    cout << ans << endl;
    return 0;
}