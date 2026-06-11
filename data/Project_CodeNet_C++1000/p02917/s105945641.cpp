#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int n;
    cin>>n;
    int b[n-1],a[n]; 
    for(int i=0;i<n-1;i++)cin>>b[i];
    int ans=b[0]+b[n-2];
    for(int i=0;i<n-2;i++){
        a[i]=min(b[i],b[i+1]);
        ans+=a[i];
    }
    cout<<ans<<endl;
    return 0;
}