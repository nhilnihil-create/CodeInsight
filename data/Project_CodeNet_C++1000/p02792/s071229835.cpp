#include<bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using namespace std;

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;

const ll INF=1LL<<60;
const ll MOD=1e9+7;

int main(){
    int N; cin >> N;
    vector<vi> cnt(10, vi(10, 0));
    ll res=0;
    for(int i=1; i<=N; i++){
        int a, b;
        a=i%10;
        b=i;
        while(b >= 10) b/=10;
        cnt[a][b]++;
    }
    for(int i=1; i<10; i++){
        for(int j=1; j<10; j++){
            res+=cnt[i][j]*cnt[j][i];
        }
    }
    cout << res << endl;
    return 0;
}