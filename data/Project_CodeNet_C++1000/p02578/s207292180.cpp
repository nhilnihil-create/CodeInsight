#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n;
    cin >> n;
    long long int a[n];
    for (int i = 0; i < n; ++i){cin >> a[i];}
    long long int ans = 0;
    for (int i = 0; i < n-1; ++i){
        if(a[i] > a[i+1]){
            ans += a[i]-a[i+1];
            a[i+1] = a[i];
        }
    }
    cout << ans << endl;
}
