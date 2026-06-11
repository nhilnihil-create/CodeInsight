#include<bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using namespace std;

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;
using vii=vector<vector<int>>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const ll MOD=1e9+7;


int main(){
    int N, M; cin >> N >> M;
    vi a(M), b(M);
    vii c(M);
    for(int i=0; i<M; i++){
        cin >> a[i] >> b[i];
        c[i].resize(b[i]);
        for(int j=0; j<b[i]; j++){
            cin >> c[i][j];
            c[i][j]--;
        }
    }
    vector<int> cost(1<<N, 1e9);
    cost[0]=0;
    for(int i=0; i<M; i++){
        int bit=0;
        for(int j=0; j<(int)c[i].size(); j++){
            bit=bit|(1<<c[i][j]);
        }
        cost[bit]=min(cost[bit], a[i]);
    }
    for(int i=0; i<(1<<N); i++){
        for(int j=0; j<(1<<N); j++){
            int bit=i|j;
            cost[bit]=min(cost[bit], cost[i]+cost[j]);
        }
    }
    if(cost[(1<<N)-1] == 1e9) cout << -1 << endl;
    else cout << cost[(1<<N)-1] << endl;
    return 0;   
}