#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int ans=0,tmp=0;
    for(int i=0;i<n-1;i++){
        if(a[i]>=a[i+1])tmp++;
        else tmp=0;
        ans=max(ans,tmp);
    }
    cout<<ans<<endl;
    return 0;
}