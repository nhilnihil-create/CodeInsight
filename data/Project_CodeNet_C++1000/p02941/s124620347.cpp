#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
int main(){
    ll n,A[200001],B[200001];
    cin>>n;
    rep(i,n) cin>>A[i];
    rep(i,n) cin>>B[i];
    ll C[200001]={0};
    rep(i,n) C[i]=B[(i-1+n)%n]+B[(i+1)%n];
    queue<int> que;
    rep(i,n) if(C[i]<=B[i]) que.push(i);
    ll ans=0;
    while(!que.empty()){
        int a=que.front();
        que.pop();
        if(C[a]>B[a]||A[a]==B[a]) continue;
        ll b=(B[a]-A[a])/C[a];
        B[a]-=b*C[a];
        C[(a-1+n)%n]-=b*C[a];
        C[(a+1)%n]-=b*C[a];
        ans+=b;
        if(C[(a-1+n)%n]<=B[(a-1+n)%n]) que.push((a-1+n)%n);
        if(C[(a+1)%n]<=B[(a+1)%n]) que.push((a+1)%n);
    }
    int x=1;
    rep(i,n) if(A[i]!=B[i]) x=0;
    if(x) cout<<ans;
    else cout<<-1;
}