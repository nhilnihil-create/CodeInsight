#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> p(n);
    for(int i=0; i<n; i++) cin >> p[i];

    int ans = 0;
    /*
    if(p[0] < p[1] && p[1] < p[2] ||
       p[2] < p[1] && p[1] < p[0] ) {
           ans++;
       }

    if(p[n-3] < p[n-2] && p[n-2] < p[n-1] ||
       p[n-1] < p[n-2] && p[n-2] < p[n-3] ) {
           ans++;
       }
*/
    for(int i=0; i<n; i++) {
        if( i == 0 || i == n-1 ) continue;
        else if( p[i-1] < p[i] && p[i] < p[i+1] 
         || p[i+1] < p[i] && p[i] < p[i-1] ) {
             ans++;
         }
    }

    cout << ans << endl;
}