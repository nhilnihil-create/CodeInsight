/*
      author  : nishi5451
      created : 15.08.2020 10:26:03
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    int sum = 0;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        sum+=a[i];
    }

    vector<int> b(n+1);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            b[i]+=a[j];
        }
    }
    int ans = 2e9;
    for(int i=1; i<n; i++){
        ans = min(ans,abs(b[i]-(sum-b[i])));
    }
    cout << ans << endl;
    return 0;
}