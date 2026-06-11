#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
    long n,k;cin>> n>> k;
    
    if(n > k) n = n%k;
    
    long ans = n;

    while(1){
        n = abs(n - k);

        if(n < ans){
            ans = n;
        }else{
            break;
        }
    }

    cout << ans << endl;
}