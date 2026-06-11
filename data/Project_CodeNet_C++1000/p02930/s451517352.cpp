#include <iostream>
using namespace std;
typedef long long ll;
ll f(ll x,ll y){
    ll i=0;
    while(1){
        if(x%2!=y%2)return i+1;
        i++;
        x/=2,y/=2;
    }
}
ll n;
int main(void){
    //cout<<f(4,8)<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            cout<<f(i,j)<<" ";
        }
        cout<<endl;
    }
}
