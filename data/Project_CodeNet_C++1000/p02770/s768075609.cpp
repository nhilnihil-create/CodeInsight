#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll cc(int n, int k){
    return (n+k-1)/k;
}

int main(){
    ll k,q;cin>>k>>q;

    vector<int> d(k);
    for(int i = 0 ; i < k; i++) cin>>d[i];

    for(int i = 0; i < q; i++){
        int n,x,m;
        cin>>n>>x>>m;
        ll last = x;
        ll eq = 0;
        for(int i = 0;  i < k; i++){
          ll num = cc(n-i-1,k);
          last+=(d[i]%m)*num;
          if(d[i]%m == 0)eq+=num;
        }
       ll ans = (n-1) - (last/m - x/m) - eq;
       cout<<ans<<endl;
    }
}
