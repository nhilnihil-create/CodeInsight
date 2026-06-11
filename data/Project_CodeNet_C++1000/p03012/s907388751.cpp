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
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    int tmp=0;
    int ans=sum;
    for(int i=0;i<n;i++){
        tmp+=a[i];
        ans=min(ans,abs(tmp-(sum-tmp)));
    }
    cout<<ans<<endl;
    return 0;
}