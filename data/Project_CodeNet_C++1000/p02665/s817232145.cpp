#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n+1];
    for(int i=0;i<=n;i++)cin>>a[i];
    long long b[n+1],wa[n+1];
    b[0]=1-a[0];
    if(b[0]<0){
        cout<<"-1"<<endl;
        return 0;
    }
    wa[0]=a[0];
    for(int i=1;i<=n;i++)wa[i]=wa[i-1]+a[i];
    for(int i=1;i<=n;i++){
        b[i]=min(2*b[i-1]-a[i],wa[n]-wa[i]);
        if(b[i]+a[i]<b[i-1] || b[i]<0){
            cout<<"-1"<<endl;
            return 0;
        }
    }
    long long x=0;
    for(int i=0;i<=n;i++)x+=a[i]+b[i];
    cout<<x<<endl;
    return 0;
}
