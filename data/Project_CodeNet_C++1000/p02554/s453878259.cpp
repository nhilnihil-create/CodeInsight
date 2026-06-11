#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=1e5+5;
typedef long long ll;
const int mod=1e9+7;
int a[2005];
int ksm(int x,int y){
    x%=mod;
    int res=1;
    while(y){
        if(y&1)res=(res*x)%mod;
        x=(x*x)%mod;
        y>>=1;
    }
    return res;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    if(n==1){
        cout<<"0"<<endl;
        return 0;
    }
    if(n==2){
        cout<<"2"<<endl;
        return 0;
    }
    int ans=(ksm(10,n)-2*ksm(9,n)+ksm(8,n)+2*mod)%mod;
    cout<<ans<<endl;



    return 0;
}
