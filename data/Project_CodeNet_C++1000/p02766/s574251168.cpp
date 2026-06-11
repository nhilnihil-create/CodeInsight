// B - Digits
#include <bits/stdc++.h>
using namespace std;

int main(){
    long n;
    int k;
    cin >> n >> k;
    int cnt = 1;
    while(1){
        if(n <= k-1) break;
        n/=k;
        // cout << n << endl;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}