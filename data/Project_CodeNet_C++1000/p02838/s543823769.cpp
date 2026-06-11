#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int mod = 1000000007;
const int MAXN = 300005;
long long bit[64]={0};
long long pow1[64]={0};
long long a[MAXN];
int maxlen = 0 ;
void add(long long a){
    int i;
    for(i=0;a;i++){
        bit[i]+=(a%2);
        a/=2;
    }
    maxlen = max(maxlen,i);
}
int main()
{
    pow1[0]=1;
    for(int i=1;i<63;i++)
        pow1[i]=pow1[i-1]*2%mod;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
        add(a[i]);
    }
    long long ans = 0 ;
    for(int j=0;j<n;j++){
        for(int i=0;i<maxlen;i++){
        if(a[j]&1)
            ans= (ans + pow1[i]*(n-bit[i])%mod)%mod;
        else
            ans= (ans + pow1[i]*bit[i]%mod)%mod;
            a[j]/=2;
        //cout << ans <<endl;
        }
    }
    cout << ans*((mod+1)/2)%mod << endl;
    return 0;
}
