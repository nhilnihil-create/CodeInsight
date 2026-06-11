//  main.cpp
//  ABC131C
#include <iostream>
#include<vector>
#include<cassert> // combinationを使う時
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
// 最大公約数
ll gcd(ll a,ll b){
    if(b>0){
        return gcd(b,a%b);
    }else{
        return a;
    }
}
// 最小公倍数
ll lcm(ll a,ll b){
    return a/gcd(a,b)*b;
}
ll f(ll i,ll j,ll k){
    ll ret=i-i/j;
    ret-=i/k;
    ret+=i/lcm(j,k);
    return ret;
}
int main(int argc, const char * argv[]) {
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    cout<<f(b,c,d)-f(a-1,c,d)<<endl;
    return 0;
}
