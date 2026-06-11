#include <bits/stdc++.h>
using namespace std;
int main(){
    long a,b;
    cin >> a >> b;
    long small,big;
    if(a<b){
        small = a;
        big = b;
    }else{
        small = b;
        big = a;
    }
    long ans = big;
    while(ans%small!=0){
        ans+=big;
    }
    cout << ans << endl;
    return 0;
}