#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int ans = 0;
    cin >> n;
    for(int a = 1; a < n; a++) {
       ans += (n-1)/a;
    }
    cout << ans << endl;
}