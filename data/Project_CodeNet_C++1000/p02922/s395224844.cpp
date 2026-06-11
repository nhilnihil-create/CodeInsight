#include<bits/stdc++.h>
using namespace std;

int main(void){
    int a, b;
    cin >> a >> b;

    int ans = 0;
    int o = 1;
    while(o < b){
        --o;
        o += a;
        ans ++;
    }
    cout << ans;

    return 0;
}