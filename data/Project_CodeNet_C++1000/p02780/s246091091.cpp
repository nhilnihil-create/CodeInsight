#include<bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using namespace std;

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const ll MOD=(ll)1e9+7;

int main(){
    int N, K; cin >> N >> K;
    vi p(N);
    for(auto &x : p) cin >> x;
    vector<double> E(N);
    for(int i=0; i<N; i++){
        E[i]=(p[i]+1)/2.0;
    }
    double sum=0;
    for(int i=0; i<K; i++){
        sum+=E[i];
    }
    double res=sum;
    for(int i=K; i<N; i++){
        sum=sum+E[i]-E[i-K];
        res=max(res, sum);
    }
    printf("%.7f\n", res);
    return 0;
}