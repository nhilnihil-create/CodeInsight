#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
    ll A,B;
    cin>>A>>B;
    ll ans=(A+B)/2;
    if((A+B)%2==0){
        cout<<ans<<endl;
    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
    }
}
