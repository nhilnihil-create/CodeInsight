#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using P = pair<int,int>;
using ll = long long; 

int main(){
    ll a,b,k;
    cin>>a>>b>>k;
    ll x,y;
    if((a+b)<k){
        x=0;
        y=0;
    }else if(a<k){
        x=0;
        y=b+a-k;
    }else{ //a>k
        x=a-k;
        y=b;
    }
    cout<<x<<" "<<y<<endl;

}
