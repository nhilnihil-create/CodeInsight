#include<iostream>
using namespace std;
using ll = long long;

ll func1(ll n,int p){
    if(n==0) return 0;
    return n/p+func1(n/p,p);
}

ll func2(ll n,int p){
    if(n%2) return 0;
    ll r=func1(n/2,p);
    if(p==2) r+=n/2;
    return r;
}

int main(){
    ll n;
    cin>>n;
    cout<<min(func2(n,2),func2(n,5))<<endl;
}