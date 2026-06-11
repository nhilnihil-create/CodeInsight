#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
    ll n;cin>>n;
    for(int i=-120;i<=120;i++){
        for(int j=-120;j<=120;j++){
            ll x=(i*i*i*i*i)-(j*j*j*j*j);
            if(x==n){
                cout << i <<" "<<j<<endl;
                return 0;
            }
        }
    }
}
