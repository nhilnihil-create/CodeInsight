#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,n) for(int i=(int)(j);i<(int)(n);i++)
#define REP(i,j,n) for(int i=(int)(j);i<=(int)(n);i++)
#define MOD 1000000007
#define int long long
#define ALL(a) (a).begin(),(a).end()
#define vi vector<int>
#define vii vector<vi>
#define pii pair<int,int>
#define priq priority_queue<int>
#define disup(A,key) distance(A.begin(),upper_bound(ALL(A),(int)(key)))
#define dislow(A,key) distance(A.begin(),lower_bound(ALL(A),(int)(key)))
#define tii tuple<int,int,int>
#define Priq priority_queue<int,vi,greater<int>>
#define pb push_back
#define mp make_pair
#define INF (1ll<<62)-1
#define MAX 1000000000
signed main(){
    int N; cin>>N;
    vi A(N),B(N);
    rep(i,0,N) cin>>A[i];
    rep(i,0,N) cin>>B[i];
    priority_queue<pii> Q;
    rep(i,0,N) Q.push(mp(B[i],i));
    int ans=0;
    while(Q.size()>0){
        int X=Q.top().first,Y=Q.top().second; Q.pop();
        int P=(Y-1+N)%N,R=(Y+1)%N;
        int S=B[P]+B[R];
        if(X<A[Y]){
            cout<<-1<<endl;
            return 0;
        }
        int Z=(X-A[Y]);
        int C=X-Z/S*S;
        if(C==A[Y]){
            B[Y]=A[Y];
            ans+=Z/S;
        }
        else if(B[Y]==C){
            cout<<-1<<endl;
            return 0;
        }
        else{
            B[Y]=C;
            ans+=Z/S;
            Q.push(mp(C,Y));
        }
    }
    cout<<ans<<endl;
}
