#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    long long k;
    cin>>k;
    long long K=-k;
    long long a[n],f[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        K+=a[i];
    }
    for(int i=0;i<n;i++)cin>>f[i];
    if(K<=0){
        cout<<"0"<<endl;
        return 0;
    }
    sort(a,a+n);
    sort(f,f+n,greater<long long>());
    long long l=0,r=1000000000000000000;
    while(r-l>1){
        long long mid=(l+r)/2;
        long long x=0;
        for(int i=0;i<n;i++)if(a[i]>mid/f[i])x+=a[i]-mid/f[i];
        if(x>k)l=mid;
        else r=mid;
    }
    cout<<r<<endl;
    return 0;
}