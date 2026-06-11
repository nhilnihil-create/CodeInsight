#include <bits/stdc++.h>
#include <string>
using namespace std;
typedef long long ll;

int main(){
    ll N,K,S;
    cin>>N>>K>>S;
    for(ll i=0;i<N-1;++i){
        if(i<K){
            cout<<S<<" ";
        }else{
            if(1000000000!=S){
                cout<<S+1<<" ";
            }else{
                cout<<1<<" ";
            }
        }
    }
    if(K==N){
            cout<<S;
        }else{
            if(1000000000!=S){
                cout<<S+1;
            }else{
                cout<<1;
            }
        }
}