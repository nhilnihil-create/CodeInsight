#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int N,X,Y; cin>>N>>X>>Y;

    vector<int> K(N-1,0);
    X--; Y--;

    rep(i,0,N){
        rep(j,i+1,N){
            int idx=min(j-i,abs(i-X)+abs(j-Y)+1)-1;
            K.at(idx)++;
        }
    }

    for(auto k:K) cout<<k<<endl;
}