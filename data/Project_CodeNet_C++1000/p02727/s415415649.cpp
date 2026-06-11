#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int64_t i=ini;i<n;i++)
#define _rep(i,ini,n) for(int64_t i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int64_t X,Y,A,B,C; cin>>X>>Y>>A>>B>>C;
    vector<int64_t> P(A),Q(B),R(C);
    rep(a,0,A) cin>>P.at(a);
    rep(b,0,B) cin>>Q.at(b);
    rep(c,0,C) cin>>R.at(c);

    sort(ToEnd(P),greater<int64_t>());
    sort(ToEnd(Q),greater<int64_t>());
    sort(ToEnd(R),greater<int64_t>());

    vector<int64_t> Ans;
    rep(x,0,X) Ans.push_back(P.at(x));
    rep(y,0,Y) Ans.push_back(Q.at(y));

    sort(ToEnd(Ans));
    
    rep(i,0,min(X+Y,C)){
        if(Ans.at(i)<R.at(i)) Ans.at(i)=R.at(i);
        else break;
    }

    int64_t ans=accumulate(ToEnd(Ans),0LL);
    cout<<ans<<endl;
}