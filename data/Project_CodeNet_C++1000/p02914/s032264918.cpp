#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxm=1e5+5;
int a[maxm];
int d[66];
int n;
void add(int x){
    for(int i=60;i>=0;i--){
        if(x>>i&1){
            if(d[i]){
                x^=d[i];
            }else{
                d[i]=x;
                break;
            }
        }
    }
}
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    int sum=0;
    for(int i=1;i<=n;i++)sum^=a[i];
    for(int j=0;j<=60;j++){
        if(sum>>j&1){//去掉奇数个的
            for(int i=1;i<=n;i++){
                if(a[i]>>j&1)a[i]^=(1LL<<j);
            }
        }
    }
    for(int i=1;i<=n;i++){
        add(a[i]);
    }
    int ans=0;
    for(int i=60;i>=0;i--){
        if((ans^d[i])>ans)ans^=d[i];
    }
    cout<<ans+(ans^sum)<<endl;
    return 0;
}