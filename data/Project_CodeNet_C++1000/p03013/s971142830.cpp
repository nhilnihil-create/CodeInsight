#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    rep(i,m){
        int b;
        cin>>b;
        a[b]++;
    }
    vector<int> dat(n+1,0);
    dat[0]=1;
    for(int i=1;i<=n;i++){
        if(a[i]!=0) continue;
        if(i-1>=0) dat[i]+=dat[i-1];
        if(i-2>=0) dat[i]+=dat[i-2];
        dat[i]%=MOD;
    }
    cout<<dat[n];
}