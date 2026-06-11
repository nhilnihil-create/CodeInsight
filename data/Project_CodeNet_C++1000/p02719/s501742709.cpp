#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
    IOS;
    long long n,k;
    cin >> n >> k;
    long long ans = n % k;
    if(ans < abs(ans - k)){
        cout << ans << endl;
    }else{
        cout << abs(ans - k) << endl;
    }
}