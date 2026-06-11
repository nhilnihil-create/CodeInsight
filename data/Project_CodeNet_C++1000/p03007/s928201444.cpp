#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<int,int> P;
int main(){
    int n,m,A[200001];
    cin>>n;
    rep(i,n) cin>>A[i];
    sort(A,A+n);
    vector<P> ans;
    rep(i,n-2){
        if(A[i+1]>=0) ans.push_back(P(A[0],A[i+1])),A[0]-=A[i+1];
        else ans.push_back(P(A[n-1],A[i+1])),A[n-1]-=A[i+1];
    }
    ans.push_back(P(A[n-1],A[0]));
    m=A[n-1]-A[0];
    cout<<m<<endl;
    rep(i,n-1) cout<<ans[i].first<<" "<<ans[i].second<<endl;
}