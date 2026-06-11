#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll solve1(ll x) {
    ll ret=1;
    for (ll i=2;i*i<=x;i++){
        if (x%i==0){
            ret+=2;
            if (x/i==i)ret--;
        }
    }
    return ret;
}
ll solve2(ll x) {
    ll ret=1,tp;
    for (ll i=2;i*i<=x;i++) {
        if (x%i==0){
            ll tmp=x/i;
            tp=x;
            while (tp%i==0){
                tp/=i;
            }
            if (tp>i)tp%=i;
            ret+=(tp==1);
            if (tmp!=i) {
                tp=x;
                while(tp%tmp==0){
                    tp/=tmp;
                }
                if (tp>tmp)tp%=tmp;
                ret+=(tp==1);
            }
        }
    }
    return ret;
}
int main(){
 ll n;
    cin>>n;
    if (n==2) {
        cout << 1;
        return 0;
    }
    cout<<solve1(n-1)+solve2(n);
    return 0;
}