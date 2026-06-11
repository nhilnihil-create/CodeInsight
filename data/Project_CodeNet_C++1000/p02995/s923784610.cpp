#include <bits/stdc++.h>
using namespace std;
using ll =long long;

ll gcd(ll a,ll b){
    if(b==0){
        return a;
    }else{
        return gcd(b,a%b);
    }
}

ll lcm(ll a,ll b){
    ll d=gcd(a,b);
    return a/d*b;
}
int main(){
    ll A,B,C,D; cin>>A>>B>>C>>D;
    A--;
    ll l=lcm(C,D);
    ll sa=A/C+A/D-A/l;
    ll sb=B/C+B/D-B/l;

    cout<<(B-sb)-(A-sa)<<endl;
}
