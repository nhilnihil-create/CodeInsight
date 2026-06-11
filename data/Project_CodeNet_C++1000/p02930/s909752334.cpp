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
#define INF (1ll<<63)-1
#define MAX 1000000000
signed main(){
    int N; cin>>N;
    vii A(N,vi(N));
    int me=1;
    REP(k,1,60){
        rep(i,0,N-1){
            rep(j,i+1,N){
                int X=j-i;
                if(X%me==0&&X/me%2==1) A[i][j]=k;
            }
        }
        me*=2;
    }
    rep(i,0,N-1){
        rep(j,i+1,N) cout<<A[i][j]<<" ";
        cout<<endl;
    }
}