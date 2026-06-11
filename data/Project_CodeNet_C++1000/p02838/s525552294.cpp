#include<bits/stdc++.h>
using namespace std;

int main(){
    const long long mod=1e9+7;
    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i=0;i<n;i++) cin >> a[i] ;
    long long ans=0;
    vector<long long> count0(61);
    vector<long long> count1(61);
    for(int i=0;i<n;i++){
        for(int j=0;j<61;j++){
            if(a[i]&1ll<<j) count1[j]++;
            else count0[j]++;
        }
    }
    long long kani=1;
    for(int i=0;i<61;i++){
        long long temp=((count0[i]*count1[i])%mod*kani)%mod;
        ans=(ans+temp)%mod;
        kani=(kani*2)%mod;
    }
    cout << ans << endl;
}