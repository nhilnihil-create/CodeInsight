#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);
    long long n,a[100005],b[100005],ans=0;
    cin>>n;
    for(int i=0;i<=n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    for(int i=0;i<n;i++){
        if(a[i]>=b[i]){
            a[i]-=b[i];
            ans+=b[i];
        }
        else if(a[i]+a[i+1]>=b[i]){
            b[i]-=a[i];
            ans+=a[i];
            a[i]=0;
            a[i+1]-=b[i];
            ans+=b[i];
        }
        else{
            ans+=a[i]+a[i+1];
            a[i]=0;
            a[i+1]=0;
        }
    }
    cout<<ans<<endl;
    return(0);
}