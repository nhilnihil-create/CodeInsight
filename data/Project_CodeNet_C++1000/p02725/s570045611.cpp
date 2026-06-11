/*
      author  : nishi5451
      created : 14.08.2020 21:40:50
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int k,n;
    cin >> k >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(),a.end());
    int len = 0;
    for(int i=1; i<n; i++){
        len = max(len,a[i]-a[i-1]);
    }
    len = max(len,k-a[n-1]+a[0]);
    cout << k-len << endl;
    return 0;
}