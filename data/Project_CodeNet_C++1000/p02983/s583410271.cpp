#include <iostream>
using namespace std;

using ll = long long;

#define mod 2019
#define INF 2<<30

int main(void){
    // Your code here!
    ll l,r;
    cin >> l >> r;
    
    if(r+1-l>=mod)
    {
        cout<<0;
        return 0;
    }
    
    int m=mod;
    
    for(int i=l;i<r;i++)for(int j=l+1;j<=r;j++)
    {
        m=min(((i%mod)*(j%mod))%mod,m);
    }
    
    cout<<m<<endl;
}

