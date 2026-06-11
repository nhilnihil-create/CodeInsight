#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

int main(){
    ll a,b,k;
    cin>>a>>b>>k;
    
    if(a>=k) a-=k;
    else if(a+b>=k){
        b-=(k-a);
        a=0;
    }
    else{
        a=0;
        b=0;
    }
    
    cout<<a<<" "<<b<<endl;
    
    return 0;
}