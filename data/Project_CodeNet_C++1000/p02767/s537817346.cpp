#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int n;
    cin>>n;
    int x[n],maxv=0,minv=101;
    long long ans=1e18;
    for(int i=0;i<n;i++){
        cin>>x[i];
        maxv=max(maxv,x[i]);
        minv=min(minv,x[i]);
        }
    for(int j=minv;j<=maxv;j++){
        long long tmp=0;
        for(int i=0;i<n;i++){
            tmp+=(j-x[i])*(j-x[i]);
        }
        ans=min(ans,tmp);
    }
    cout<<ans<<endl;
    return 0;
}