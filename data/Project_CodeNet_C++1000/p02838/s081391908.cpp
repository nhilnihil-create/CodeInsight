#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int main(){
    ll n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;++i)cin>>a[i];
    ll ans = 0; 
    ll mul = 1;             //mul = multiplier --> (power of 2)
    for(int j=1;j<=64;++j){
        ll count_e = 0,count_o = 0;         //count of even and odd numbers among n elements
        for(int i=0;i<n;++i){
            if(a[i]&1)count_o++;
            else count_e++;
            a[i] = (a[i]>>1);           //right shift so that the elements will be ready to be judged in the next iteration if it's even or odd
        }
        ll pairs = (count_o*count_e)%mod;   // total no.of pairs whose product of those two respective nums has it's last digit as set (1) 
        ans = (ans + pairs*mul)%mod;
        mul = (mul*2)%mod;
    }
    cout<<ans;
}