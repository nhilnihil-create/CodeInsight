#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,t,cnt=1;
ll gcd(ll a, ll b) {
    return b==0? a: gcd(b, a%b);
}
int main() {
    cin>>a>>b;
    t=gcd(a,b);
    for(ll i=2;i*i<=t;i++) {
        if(t%i==0) {
            cnt++;
            while(t%i==0) t/=i;
        }
    }
    if(t>1) cnt++;
    cout<<cnt<<endl;
    return 0;
}
