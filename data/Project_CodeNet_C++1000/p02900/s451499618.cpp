#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,cnt;
int main() {
    cin>>a>>b;
    set<ll> sa,sb;
    set<ll>::iterator it;
    sa.insert(1);
    sb.insert(1);
    for(ll i=2;i*i<=a;i++) {
        if(a%i==0) {
            sa.insert(i);
            while(a%i==0) a/=i;
        }
    }
    if(a>1) sa.insert(a);
    for(ll i=2;i*i<=b;i++) {
        if(b%i==0) {
            sb.insert(i);
            while(b%i==0) b/=i;
        }
    }
    if(b>1) sb.insert(b);
    for(it=sa.begin();it!=sa.end();it++) {
        if(sb.count(*it)) cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}