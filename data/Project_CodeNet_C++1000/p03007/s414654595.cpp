#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define RFOR(i,l,r) for(long long i=(l);i>=(r);--i)
#define RREP(i,n) RFOR(i,N-1,0)
#define RREPS(i,n) RFOR(i,N,1)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
const int INF=1e18;
const int MOD=1e9+7;

signed main(){
    int N;cin>>N;
    bool allp=true,allm=true;
    vector<int>A(N),ABS(N);
    REP(i,N){
        cin>>A[i];
        if(A[i]>=0)allm=false;
        if(A[i]<=0)allp=false;
        ABS[i]=abs(A[i]);
    }
    sort(all(ABS));
    int z=ABS[0];
    queue<int>P;
    queue<int>M;
    bool check=true;
    if(allm||allp)check=false;
    int ans=0;
    REP(i,N){
        if(check||z<abs(A[i])){
            if(A[i]>0)P.push(A[i]);
            if(A[i]<0) M.push(A[i]);
            if(A[i]==0){
                if(M.size()==0)M.push(0);
                else P.push(0);
            }
            ans+=abs(A[i]);
        }
        else{
            check=true;
            ans-=abs(A[i]);
            if(A[i]>=0)M.push(A[i]);
            else P.push(A[i]);
        }
    }
    cout<<ans<<endl;
    REP(i,N-1){
        if(P.size()>1){
            int p=P.front();P.pop();
            int m=M.front();M.pop();
            cout<<m<<" "<<p<<endl;
            M.push(m-p);
        }
        else{
            int p=P.front();P.pop();
            int m=M.front();M.pop();
            cout<<p<<" "<<m<<endl;
            P.push(p-m);
        }
    }
}