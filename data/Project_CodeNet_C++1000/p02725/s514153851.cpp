#include <stdio.h>
#include <iostream>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define repl(i,l,r) for(int i=l;i<r;i++)
using ll = long long;
const ll MOD=1e9+7;
const ll INF=9e18+10;
const int inf=2e9+10;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};


int main(){
        int k,n;cin>>k>>n;
        int A[n];
        rep(i,n)cin>>A[i];
        int subans=k+A[0]-A[n-1];
        for(int i=1;i<n;i++){
        subans=max(subans,A[i]-A[i-1]);
        }
        cout<<k-subans<<endl;
        return 0;
}