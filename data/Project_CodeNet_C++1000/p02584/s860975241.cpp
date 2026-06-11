#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

int main(){
    LL X, K, D;
    cin>>X>>K>>D;

    if(X<0)X=-X;

    if(K<=X/D){
        cout<<X-D*K;
    }else{
        K-=X/D;
        X=X%D;
        LL Y=D-X;

        if(K%2==0){
            cout<<X;
        }else{
            cout<<Y;
        }
    }

    return 0;
}
