#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    long long n,k,ans=0;
    cin >> n >>k;
    for(int i=k;i<=n+1;i++){
        ans+=i*(n-i+1)%1000000007+1;
        if(ans>=1000000007){
            ans%=1000000007;
        }
    }
    
    cout << ans <<endl;
}
