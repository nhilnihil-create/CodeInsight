#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a,a+n);
    reverse(a,a+n);
    long ans= a[0];
    for(int i=1;i<n/2;i++){
        ans += 2*a[i];
    }
    if(n%2) ans += a[n/2];
    cout << ans << endl;
}
