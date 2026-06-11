#include<bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using namespace std;

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const int MOD=2019;

int N, D, A;
vector<ll> X, H;
vi ids;

int bin_search(int i){
    int left=i, right=N;
    while(right-left > 1){
        int mid=left+(right-left)/2;
        if(X[ids[mid]]-X[ids[i]] <= 2*D) left=mid;
        else right=mid;
    }
    return left;
}

int main(){
    cin >> N >> D >> A;
    X.resize(N), H.resize(N);
    for(int i=0; i<N; i++){
        cin >> X[i] >> H[i];
    }
    ids.resize(N);
    for(int i=0; i<N; i++) ids[i]=i;
    sort(all(ids), [&](int i, int j){return X[i]<X[j];});
    vector<ll> s(N+1, 0);
    ll ans=0;
    for(int i=0; i<N; i++){
        if(s[i] < H[ids[i]]){
            int dmg=(H[ids[i]]-s[i]+A-1)/A*A;
            int pos=bin_search(i);
            s[i]+=dmg;
            s[pos+1]-=dmg;
            ans+=dmg/A;
        }
        s[i+1]+=s[i];
    }
    cout << ans << endl;
    return 0;
}