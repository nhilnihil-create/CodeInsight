#include<bits/stdc++.h>
using namespace std;
long ncrmodp(long n,long r,long p){
    long ans = 1;
    for(long i=n-r+1;i<=n;i++){
        ans *= i;
        ans %= p;
    }
    long tmp = 1;
    for(long i=2;i<=r;i++){
        tmp *= i;
        tmp %= p;
    }
    for(long i=1;i<=p-2;i*=2){
        if(i & p-2){
            ans *= tmp;
            ans %= p;
        }
        tmp *= tmp;
        tmp %= p;
    }
    return ans;
}
int main(){
    int n,k;
    cin >> n >> k;
    long const mod = 1e9+7;

    for(int i=1;i<=k;i++){
        long tmp = ncrmodp(n-k+1,i,mod);

        tmp *= ncrmodp(k-1,i-1,mod);
        tmp%=mod;
        cout << tmp<<endl;
        
    }
    
}