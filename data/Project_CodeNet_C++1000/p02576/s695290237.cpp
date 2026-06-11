#include<iostream>
using namespace std;

int main(){
    int n,x,t;cin>>n>>x>>t;
    int ans=1;
    int tmp=x;
    while(1){
        if(tmp>=n)break;
        tmp+=x;
        ans++;
    }
    cout<<ans*t<<endl;
    return 0;
}