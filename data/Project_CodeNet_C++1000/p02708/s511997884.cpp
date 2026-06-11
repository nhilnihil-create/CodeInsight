#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n,k;
    cin >> n >> k;
    long long ans=0;
    for(long long i=k;i<=n+1;i++){
        long long min=(i-1)*i/2;
        long long max=(2*n-i+1)*i/2;
        ans+=max-min+1;
        ans%=1000000007;
    }
    cout << ans << endl;
    return 0;
}