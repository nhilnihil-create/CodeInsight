#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int N; cin>>N;

    vector<vector<int>> V(9,vector<int>(9,0));
    rep(i,1,10){
        rep(j,1,10){
            rep(k,1,7){
                if(i!=j && k==1) continue;
                if(k==1){
                    if(i<=N) V.at(i-1).at(j-1)++;
                    continue;
                }

                int n=i*pow(10,k-1)+j;
                rep(l,0,pow(10,k-2)){
                    int _n=n+10*l;
                    if(_n<=N) V.at(i-1).at(j-1)++;
                }
            }
        }
    }

    int64_t ans=0;
    rep(i,0,9)rep(j,0,9){
        ans+=V.at(i).at(j)*V.at(j).at(i);
    }

    cout<<ans<<endl;
}