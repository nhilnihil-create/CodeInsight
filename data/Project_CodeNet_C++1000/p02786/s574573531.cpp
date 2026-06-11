#include <bits/stdc++.h>
using namespace std;

long long atack(long long x){
    if(x==1){
        return 1; 
    }
    long long y=2*atack(x/2);
    return y+1;
}

int main(void){
    // Your code here!
    long long H;cin>>H;
    long long ans=atack(H);
    cout<<ans<<endl;
    return 0;
}
