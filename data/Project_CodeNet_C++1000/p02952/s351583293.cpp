#include <bits/stdc++.h>
using namespace std;
using ll =long long;

int main(){
    ll N; cin>>N;
    if(N<=9){
        cout<<N<<endl;
    }else if(N<=99){
        cout<<9<<endl;
    }else if(N<=999){
        cout<<9+N-99<<endl;
    }else if(N<=9999){
        cout<<909<<endl;
    }else if(N<=99999){
        cout<<909+N-9999<<endl;
    }else{
        cout<<90909<<endl;
    }
}