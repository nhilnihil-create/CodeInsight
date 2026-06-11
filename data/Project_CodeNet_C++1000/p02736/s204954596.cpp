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
const int MAX=200001;

int COM(int n,int r){
    while(n!=0&&r!=0){
        if(!(n%2)&&(r%2))return 0;
        n/=2;r/=2;
    }
    return 1;
}

signed main(){
    int N;string S;cin>>N>>S;
    int A[N];
    bool oexist=false;
    REP(i,N){
        A[i]=S[i]-'1';
        if(A[i]==1)oexist=true;
    }
    int sum=0;
    if(oexist){
        REP(i,N){
            if(A[i]==1)sum+=COM(N-1,i);
        }
        cout<<(sum%2==0?0:1)<<endl;
    }
    else{
        REP(i,N){
            if(A[i]==2)sum+=COM(N-1,i);
        }
        cout<<(sum%2==0?0:2)<<endl;
    }
}