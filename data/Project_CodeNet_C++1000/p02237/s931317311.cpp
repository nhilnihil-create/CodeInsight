#include<bits/stdc++.h>

#define rep(i,n) for(int (i)=0;(i)<(n);++(i))
#define FOR(i,a,b) for(int (i)=(a);i<(b);++(i))
#define ALL(obj) (obj).begin(),(obj).end()
#define space <<" "<<
#define ll long long
#define bpm %1000000007

using namespace std;

ll powAns(ll,ll);

int main(){
    int n,u,k;
    int a;
    cin>>n;
    int vec[n][n];

    rep(i,n)rep(j,n)vec[i][j]=0;

    rep(i,n){
        cin>>u>>k;
        rep(j,k){
            cin>>a;
            vec[u-1][a-1]=1;
        }
    }
    rep(i,n){
        rep(j,n-1)cout<<vec[i][j]<<" ";
        cout<<vec[i][n-1]<<endl;
    }
}

ll powAns(ll m ,ll n){
    ll res=1;
    while(n>0){
        if(n & 1)res = res*m bpm;

        m=m*m bpm;
        n>>=1;
    }

    return res;
}

