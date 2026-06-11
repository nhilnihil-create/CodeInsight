#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
const int MOD=1e9+7;
const int INF=1e18;

signed main(){
    int X;cin>>X;
    bool T[100200];
    REP(i,100200)T[i]=false;
    T[0]=true;
    REP(k,1000){
        REP(i,100000){
            if(T[i])T[i+100]=T[i+101]=T[i+102]=T[i+103]=T[i+104]=T[i+105]=true;
        }
    }
    cout<<(T[X]?1:0)<<endl;
}
