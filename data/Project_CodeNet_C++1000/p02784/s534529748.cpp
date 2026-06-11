#include<bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using namespace std;

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const int MOD=1e9+7;

int main(){
    int H, N; cin >> H >> N;
    vi A(N);
    for(auto &x : A) cin >> x;
    ll sum=0;
    for(int i=0; i<N; i++){
        sum+=A[i];
    }
    cout << (H <= sum ? "Yes":"No") << endl;
    return 0;
}