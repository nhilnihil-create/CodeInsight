#include <iostream>
#include <string>
using namespace std;
typedef long long int ll;
ll  p ;
ll power()  
{  
    ll res = 1;   
    ll x =  10;
    x = x % p; 
   
    if (x == 0) return 0; 
    ll y = p-2;
    while (y > 0)  
    {  
        if (y & 1)  
            res = (res*x) % p;  
        y = y>>1; 
        x = (x*x) % p;  
    }  
    return res;  
}  
int main() {
    int n;cin>>n;
    cin>>p;
    string s;cin>>s;
    ll p10[n+1] = {0} , in = power();
    p10[0] = 1;
    for (int i=1;i<n+1;++i)p10[i] = (p10[i-1] * in)%p;
    ll sum = 0 ,ans = 0;
    ll cnt[p] = {0};cnt[0] =1;
    for (int i=0;i<n;++i){
        sum = (sum *10 + (s[i] - '0'))%p;
        ll t1 = sum;
        if (in)
        sum = (p10[i+1] *sum)%p;
        if (in == 0) {if (sum == 0){
            ans+=(i+1);
        }}else{
        ans += (cnt[sum]);
        ++cnt[sum];}
        sum = t1;
    }
    cout<<ans;
}