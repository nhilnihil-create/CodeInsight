#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
const int inf=1e9+7;
const ll mod=1e9+7;
const ll big=1e9+7;

int N, M;
vector<pair<int, int> > key;
ll DP[(1<<15)];

ll solve(int S){
    if(DP[S] > -1) return DP[S];
    DP[S] = big;
    int tmpS;
    for(int i=0;i<N;++i){
        if((S&(1<<i))!=0){
            for(int j=0;j<M;++j){
                if((key[j].fi&(1<<i))!=0){
                    tmpS = S;
                    for(int k=0;k<N;++k){
                        if(key[j].fi&(1<<k)){
                            if(tmpS&(1<<k)){
                                tmpS -= (1<<k);
                            }
                        }
                    }
                    DP[S] = min(DP[S], solve(tmpS) + key[j].se);
                }
            }
        }
    }
    return DP[S];
}

int main() {
    for(int i=0;i<(1<<15);++i){
        DP[i] = -1;
    }
    DP[0] = 0;
    cin>>N>>M;
    int a, b, c;
    int tmpkey;
    for(int i=0;i<M;++i){
        cin>>a>>b;
        tmpkey = 0;
        for(int j=0;j<b;++j){
            cin>>c;
            c--;
            tmpkey += (1<<c);
        }
        key.push_back(mp(tmpkey, a));
    }
    ll ans = solve((1<<N)-1);
    if(ans==big) cout<<-1<<endl;
    else cout<<ans<<endl;
}
