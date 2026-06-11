#include<bits/stdc++.h>
using namespace std;

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;
using vii=vector<vector<int>>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const ll MOD=1e9+7;

int main(){
    int N, K, Q;
    cin >> N >> K >> Q;
    vi A(Q), cnt(N, 0);
    vector<bool> res(N, 1);
    for(int i=0; i<Q; i++){
        cin >> A[i];
        A[i]--;
        cnt[A[i]]++;
    }
    for(int i=0; i<N; i++){
        if(K-(Q-cnt[i]) <= 0) res[i]=0;
    }
    for(int i=0; i<N; i++){
        cout << (res[i] ? "Yes":"No") << endl;
    }
    return 0;
}