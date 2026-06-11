#include<bits/stdc++.h>
#define REP(i,n) for(int i=0,i##_len=int(n);i<i##_len;++i)
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define All(x) (x).begin(),(x).end()
#define rAll(x) (x).rbegin(),(x).rend()
using namespace std;
using ll = long long;

int main(){
    int k,q;cin>>k>>q;
    vector<int> d(k);
    REP(i, k) cin >> d[i];
    vector<ll> conv(k);
    REP(_,q){
        int n,x,m;cin>>n>>x>>m;
        REP(i,k) conv[i]=d[i]%m;
        ll y=x;
        ll res=n-1;
        REP(i,k){
            ll cnt=((n-i-1)+k-1)/k;
            if(n-1<=i) cnt=0;
            if(conv[i]==0) res-=cnt;
            y+=cnt*conv[i];
        }
        res-=y/m-x/m;
        cout<<res<<endl;
    }
}
