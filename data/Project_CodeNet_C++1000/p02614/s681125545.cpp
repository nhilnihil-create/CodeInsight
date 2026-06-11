#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define INF 10000000000
#define MOD 1000000007
using ll = long long;
using Graph = vector<vector<int>>;

int main(){
    int H,W,K; cin>>H>>W>>K;
    vector<string> S(H);
    rep(i,H)cin>>S.at(i);

    int res = 0;
    for(int h = 0; h < (1<<H); h++){
        for(int w = 0; w < (1<<W); w++){
            int tmp = 0;
            rep(i,H)rep(j,W){
                if(h&(1<<i))continue;
                if(w&(1<<j))continue;
                if(S.at(i).at(j)=='#')tmp++;
            }
            if(tmp==K)res++;
        }
    }
    cout<<res<<endl;
}