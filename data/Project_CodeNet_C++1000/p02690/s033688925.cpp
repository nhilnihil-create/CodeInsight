#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
        ll llimit=-1000,ulimit=1000;
        ll x; cin>>x;
        unordered_map<ll,ll> a;
        auto compute=[&](ll y) { return y*y*y*y*y; };
        for(int i=llimit;i<=ulimit;i++){
                a[i]=compute(i);
        }
        for(int i=llimit+1;i<=ulimit;i++){
                for(int j=llimit;j<i;j++){
                        if(a[i]-a[j]==x){ cout<<i<<" "<<j<<endl; return 0; }
                }
        }
}
