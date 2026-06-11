#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int INF=1e9;
const ll LINF=1e18;

int ans[501][501];

void solve(int l,int r,int level){
    if(r-l==1)return;
    int b=(l+r)/2;
    for(int i=l;i<b;i++){
        for(int j=b;j<r;j++){
            ans[i][j]=level;
        }
    }
    solve(l,b,level+1);
    solve(b,r,level+1);
}

int main(){
    int n;
    cin>>n;
    solve(0,n,1);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}