#include<iostream>

int32_t main(){
    int n;
    std::cin>>n;
    long long ans=1, tot=n;
    while(tot%360){
        ans++;
        tot+=n;
    }
    std::cout<<ans<<'\n';
}
