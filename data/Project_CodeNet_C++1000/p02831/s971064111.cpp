#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll gcd(ll a,ll b){
    if(b%a==0) return a;
    else return gcd(b%a,a);
}
int main(void){
    ll a,b;
    cin>>a>>b;
    cout<<a/gcd(a,b)*b<<endl;

}
