#include<iostream>
#include<cstdio>
typedef long long ll;
using namespace std;
int main(){
    int m;cin>>m;
    ll sum=0;
    ll bit=0;
    for(int i=1;i<=m;i++){
        ll a,b;
        cin>>a>>b;
        sum+=a*b;
        bit+=b;
    }
    ll x=sum/9;   
    if(sum%9==0) x--;
    ll y=bit-1;    
    cout<<x+y<< endl;
    return 0;
}