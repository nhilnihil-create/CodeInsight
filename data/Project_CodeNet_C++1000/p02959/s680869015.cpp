#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n+1],b[n];
    for(int i=0;i<=n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    long long ans=0;
    for(int i=0;i<n;i++){
        if(a[i]+a[i+1]>=b[i]){
            ans+=b[i];
            if(b[i]>=a[i]){
                a[i+1]-=b[i]-a[i];
            }
        }else{
            ans+=a[i]+a[i+1];
            a[i+1]=0;
        }
    }
    cout<<ans<<endl;
    return 0;
}