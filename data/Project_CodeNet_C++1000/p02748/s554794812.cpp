#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int A,B,M;
    cin>>A>>B>>M;

    vector<int> vA(A),vB(B);
    int minA=INT_MAX,minB=INT_MAX;
    rep(a,0,A){
        cin>>vA.at(a);
        minA=min(minA,vA.at(a));
    }
    rep(b,0,B){
        cin>>vB.at(b);
        minB=min(minB,vB.at(b));
    }

    uint64_t minP=minA+minB;
    rep(m,0,M){
        int x,y,c;
        cin>>x>>y>>c;

        uint64_t price=vA.at(x-1)+vB.at(y-1)-c;
        minP=min(minP,price);
    }

    cout<<minP<<endl;
}