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
    int N; cin >> N;
    vi d(N);
    for(auto &x : d){
        cin >> x;
    } 
    ll res=0;
    for(int i=0; i<N-1; i++){
        for(int j=i+1; j<N; j++){
            res+=d[i]*d[j];
        }
    }
    cout << res << endl;
    return 0;
}