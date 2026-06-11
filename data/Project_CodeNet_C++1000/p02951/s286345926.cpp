#include <bits/stdc++.h>
using namespace std;
using ll =long long;

int main(){
    ll A,B,C; cin>>A>>B>>C;
    if(A-B>=C){
        cout<<0<<endl;
    }else{
        cout<<C-(A-B)<<endl;
    }
}