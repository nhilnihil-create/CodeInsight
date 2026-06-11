#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define sz(x) int(x.size())
#define pb push_back
#define eb emplace_back
using ll=long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
const ll MOD=1000000007;



int main() {
    string S;
    cin>>S;
    reverse(S.begin(),S.end());
    vector<vector<ll>> dp(sz(S)+1,vector<ll>(13));
    int multi=1;
    dp.at(0).at(0)=1;
    rep(i,sz(S)){
        int x;
        if(S.at(i)=='?'){x=-1;}
        else{x=S.at(i)-'0';}

        if(x==-1){
            vector<int> nex(10);
            rep(j,10){
                nex.at(j)=j*multi%13;
            }
            rep(j,13){
                rep(k,10){
                    dp.at(i+1).at((j+nex.at(k))%13)+=dp.at(i).at(j);
                    dp.at(i+1).at((j+nex.at(k))%13)%=MOD;
                }
            }
        }
        else{
            x*=multi;
            x%=13;
            rep(j,13){
                dp.at(i+1).at((j+x)%13)+=dp.at(i).at(j);
                dp.at(i+1).at((j+x)%13)%=MOD;
            }
        }

        multi*=10;
        multi%=13;
    }

    cout<<dp.at(sz(S)).at(5)<<endl;
    
}