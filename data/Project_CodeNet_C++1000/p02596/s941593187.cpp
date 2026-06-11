#include <bits/stdc++.h>
using namespace std;
using ll =long long;

int main(){
    ll K; cin>>K;
    ll seven[K+1];
    seven[0]=7%K;
    for(ll i=1;i<K+1;i++){
        seven[i]=(seven[i-1]*10+7)%K;
    }
    for(ll i=0;i<K+1;i++){
        if(seven[i]==0){
            cout<<i+1<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
}