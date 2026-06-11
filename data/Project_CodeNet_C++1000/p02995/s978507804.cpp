#include<iostream>
using namespace std;
using ll = long long;

ll a,b,c,d;

ll gcd(ll x,ll y){
    return y==0 ? x : gcd(y,x%y);
}

ll lcm(ll x,ll y){
    return x/gcd(x,y)*y;
}

ll f(ll x){
    return x/c+x/d-x/lcm(c,d);
}

int main(){
    cin>>a>>b>>c>>d;
    cout<<(b-a+1)-(f(b)-f(a-1))<<endl;
}