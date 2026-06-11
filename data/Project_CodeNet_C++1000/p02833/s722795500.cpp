#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()

int main(){
    long long n;
    cin >> n;

    if(n % 2 == 0){//偶数
        long long cur = 5;
        long long ans = 0;
        while(2 * cur <= n){
            ans += n/(2 * cur);
            cur *= 5;
        }
        cout << ans << endl;
    } 
    else{//奇数
        cout << 0 << endl;
    }
}