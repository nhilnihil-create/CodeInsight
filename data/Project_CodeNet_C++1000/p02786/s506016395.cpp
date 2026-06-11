#include<iostream>
#include<vector>
using namespace std;

int main(){
    long long h;
    cin>>h;
    long long ans=0;
    long long cur=1;
    while(h>0){
        h/=2;
        ans+=cur;
        cur*=2;
    }
    
    cout<<ans<<endl;
}
    