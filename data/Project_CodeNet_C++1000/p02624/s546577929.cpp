#include<bits/stdc++.h>
using namespace std;
int main(){
    long n;
    cin>>n;
    long ans=0;
    for(auto i=1;i<=n;i++){
        long cnt=0,hi=0,lo=0;
        lo = i;
        hi = (n/i)*i;
        cnt = hi/i ; 
        ans += cnt*(lo+hi)/2;
        
    }
    cout<<ans;
    return 0;
}