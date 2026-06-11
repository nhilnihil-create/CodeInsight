#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
    IOS;
    long long a;
    cin >> a;
    long long pow = 1;
    long long ans = 0;
    while(a>0){
        ans += pow;
        a /= 2;
        pow *= 2;
    }
    cout << ans <<endl;
}