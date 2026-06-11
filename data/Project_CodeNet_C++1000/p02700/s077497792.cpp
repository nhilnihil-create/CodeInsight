#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll A,B,C,D;
    cin>>A>>B>>C>>D;
    while(true){
        if(0<C-B){
            C-=B;
        }else{
            cout<<"Yes";
            break;
        }
        if(0<A-D){
            A-=D;
        }else{
            cout<<"No";
            break;
        } 
    }
}