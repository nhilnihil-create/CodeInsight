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
int N,M,V,P;
bool f(vi &A,int B){
    int sum=0,Y=N-(B-P+1),Z=M-A[N-P]+A[N-B];
    rep(i,N-B,N-P){
        int X=A[N-P]-A[i];
        if(X>M) return 0;
        sum+=X;
    }
    return A[N-P]-A[N-B]<=M*V&&sum+Y*M+Z*(B-P+1)>=M*V;
}
signed main(){
    cin>>N>>M>>V>>P;
    vi A(N);
    rep(i,0,N) cin>>A[i];
    sort(ALL(A));
    int left=P,right=N;
    while(left+1<right){
        int mid=(left+right)/2;
        if(f(A,mid)) left=mid;
        else right=mid;
    }
    int ans=left;
    if(f(A,right)) ans=right;
    cout<<ans<<endl;
}