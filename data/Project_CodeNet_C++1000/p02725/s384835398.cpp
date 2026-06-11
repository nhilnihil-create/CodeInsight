#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define rep(i,s,e) for(int i=s;i<e;i++)
#define endl '\n'
int main(){
    int k,n;cin>>k>>n;
    vector<int>A(n),D(n);
    rep(i,0,n)cin>>A[i];
    rep(i,0,n-1)D[i]=A[i+1]-A[i];
    D[n-1]=abs(k+A[0]-A[n-1]);
    int diff=0;
    for(int d:D){
        diff=max(diff,d);
    }
    cout<<k-diff<<endl;
}