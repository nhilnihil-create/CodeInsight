#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(15);

    long long n;
    cin>>n;
    if(n%2!=0){
        cout<<0<<endl;
        return 0;
    }
    
    long long ans=0,fives=10;
    while(fives<=n){
        ans+=n/fives;
        fives*=5;
    }
    cout<<ans<<endl;
    return 0;
}