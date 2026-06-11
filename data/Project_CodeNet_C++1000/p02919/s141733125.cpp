#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb emplace_back
typedef long long ll;
typedef pair<int,int> pint;

int n,pi;
int nid[100002];
int main(){
    cin>>n;
    rep(i,n){
        cin>>pi;
        nid[pi]=i;
    }
    ll ans=0;
    multiset<int> s;
    s.insert(-1),s.insert(n);s.insert(-1),s.insert(n);
    for(int i=n;i>0;--i){
        auto it=s.insert(nid[i]);
        int c=*it;
        ++it;
        ll r1=*it;++it;
        ll r2=*it;--it,--it,--it;
        ll l1=*it;--it;
        ll l2=*it;
        ans+=(ll)i*((r2-r1)*(c-l1)+(l1-l2)*(r1-c));
    }
    cout<<ans<<endl;
    return 0;
}