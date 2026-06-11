#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
using namespace std;
int main(){
    long long n,ans=0;
    cin>>n;
    long long b[n-1],a[n];
    f(i,0,n-1){
        cin>>b[i];
    }
    a[0]=b[0];
    a[n-1]=b[n-2];
    f(i,1,n-1){
        if(b[i-1]<b[i]){
            a[i]=b[i-1];
        }
        else{
            a[i]=b[i];
        }
    }
    f(i,0,n){
        ans+=a[i];
    }
    cout<<ans<<endl;
    return 0;
}
