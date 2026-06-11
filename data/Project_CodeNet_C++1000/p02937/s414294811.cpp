#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,0,n+1)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
const int MOD=1e9+7;
const int INF=1e18;

signed main(){
    string S,T;cin>>S>>T;
    vector<set<int>> pls;
    pls.assign(26,set<int>({INF}));
    REP(i,S.size()){
        pls[S[i]-'a'].insert(i);
    }
    bool ok=true;
    REP(i,T.size()){
        if(*pls[T[i]-'a'].lower_bound(0)==INF){
            ok=false;
            break;
        }
    }
    int before=-1;
  	int count=0;
    if(ok){
        REP(i,T.size()){
            int d=*pls[T[i]-'a'].upper_bound(before);
      	    if(d!=INF)before=d;
      	    else{
                count++;
                before=-1;
                i--;
            }
        }
    }
  	if(ok)cout<<1+before+count*S.size()<<endl;
  	else cout<<-1<<endl;
}