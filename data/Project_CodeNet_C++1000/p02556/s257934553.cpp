#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
ll codx[200000+5],cody[200000+5];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>codx[i]>>cody[i];
    ll min1=0x7f7f7f7f;
    ll min2=0x7f7f7f7f;
    ll max1=-0x7f7f7f7f;
    ll max2=-0x7f7f7f7f;
    for(int i=1;i<=n;i++){
        max1=max(max1,codx[i]+cody[i]);
        max2=max(max2,codx[i]-cody[i]);
        min1=min(min1,codx[i]+cody[i]);
        min2=min(min2,codx[i]-cody[i]);
    }
    cout<<max(max1-min1,max2-min2)<<endl;
    return 0;
}