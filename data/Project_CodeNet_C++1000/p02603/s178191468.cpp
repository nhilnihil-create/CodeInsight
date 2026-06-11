#include <bits/stdc++.h>
using namespace std;
long n, a1, a2, ans = 1000;
int main(){
    cin >> n >> a1;
    while(--n){
        a2 = a1; cin >> a1;
        if(a1 > a2) ans += ans/a2*(a1-a2);
    }
    cout << ans << endl;
}