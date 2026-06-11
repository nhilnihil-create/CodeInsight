#include <bits/stdc++.h>
using namespace std;

int main(){
    
    long long int n,k;
    cin >> n >> k;
    
    long long int ans=0;
    for(long long int i=k; i<=n+1; i++){
        ans+=i*n-i*i+i+1;
        //cout << ans << endl;
        if(ans>=1000000007) ans%=1000000007;
    }
    cout << ans << endl;
}