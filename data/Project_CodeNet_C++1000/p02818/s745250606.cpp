#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int a,b,k;
    cin>>a>>b>>k;
    if(k>a){
        k=k-a;
        a=0;
    }
    else{
        a=a-k;
        k=0;
    }
    //cout<<a<<" "<<k;
    if(k!=0){
        if(k>b){
            k=k-b;
            b=0;
        }
        else{
            b-=k;
            k=0;
        }
    }
    cout<<a<<" "<<b;
    return 0;
}