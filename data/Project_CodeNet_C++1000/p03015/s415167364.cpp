#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <numeric>
using namespace std;
typedef long long ll;
ll mod=1e9+7;

ll power(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1)res=res*a %mod;
        a=a*a %mod;
        b/=2;
    }
    return res;
}

int main(){
    string s;cin>>s;
    ll ans=0,count=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='1'){
            ans+=power(2,count)*power(3,s.size()-i-1);
            ans%=mod;
            count++;
        }
    }
    ans+=power(2,count);
    cout<<ans%mod;
}