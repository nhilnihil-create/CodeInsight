#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n,k;
    cin >> n >> k;
    long long a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    long long mod=1000000007;
    long long b=0,c=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i]>a[j]) b++;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]) c++;
        }
    }
    long long ans;
    long long d=(k*(k-1)/2LL)%mod;
    ans=(c*k+b*d)%mod;
    cout << ans << endl;
}