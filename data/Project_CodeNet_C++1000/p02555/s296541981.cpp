#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=1e5+5;
typedef long long ll;
const int mod=1e9+7;
int a[2005];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    if(n<3){
        cout<<"0"<<endl;
        return 0;
    }
    a[1]=0;
    a[2]=0;
    a[3]=1;
    a[4]=1;
    a[5]=1;
    a[6]=2;
    a[7]=3;

    for(int i=8;i<=n;i++){
        a[i]=(a[i-1]+a[i-3])%mod;
    }
    cout<<a[n]<<endl;


    return 0;
}
