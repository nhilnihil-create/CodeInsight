#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001001001001
#define mod 1000000007
#define mod2 998244353
#define pi acos(-1)
#define all(v) v.begin(),v.end()
int main(){
    ll a,b,k;cin>>a>>b>>k;
    if(a>=k){
        a-=k;
        cout<<a<<" "<<b<<endl;
        return 0;
    }else{
        k-=a;
        a=0;
    }
    if(b>k){
        b-=k;
        cout<<a<<" "<<b<<endl;
        return 0;
    }else{
        cout<<0<<" "<<0<<endl;
        return 0;
    }

}