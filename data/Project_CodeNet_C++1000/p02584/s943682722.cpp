#include <bits/stdc++.h>
using namespace std;
using ll =long long;

int main(){
    ll X,K,D; cin>>X>>K>>D;
    ll now=abs(X);
    ll num=min(K,now/D);
    K-=num;
    now-=num*D;

    if(K%2==0){
        cout<<now<<endl;
    }else{
        cout<<D-now<<endl;
    }
}