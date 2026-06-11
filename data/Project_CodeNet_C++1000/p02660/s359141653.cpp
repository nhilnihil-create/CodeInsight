#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define RFOR(i,l,r) for(long long i=(l);i>=(r);--i)
#define RREP(i,n) RFOR(i,n-1,0)
#define RREPS(i,n) RFOR(i,n,1)
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
    int n;cin>>n;
    int ans=0;
    if(n==1){
        cout<<0<<endl;
        return 0;
    }
    int c=n;
    map<int,int>memo;
  	memo.clear();
    for(int i=2;i<=sqrt(n);i++){
        while(c%i==0){
            c/=i;
            memo[i]++;
        }
    }
    if(c!=1)memo[c]++;
    for(auto v:memo){
      	int sum=0;
        for(int i=1;sum+i<=v.second;i++){
          ans++;	
          sum+=i;
        }
    }
    cout<<ans<<endl;
}
