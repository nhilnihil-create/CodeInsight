#include<bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using namespace std;

using ll=long long;
using ld=long double;
using pii=pair<int, int>;
using vi=vector<int>;
using vii=vector<vector<int>>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const int MOD=1e9+7;

template<typename T> bool chmin(T &a,const T b){if(a>b){a=b; return true;}return false;}
template<typename T> bool chmax(T &a,const T b){if(a<b){a=b; return true;}return false;}

int main(){
    int N, K; cin >> N >> K;
    vi A(N);
    for(auto &x : A) cin >> x;

    ll sum=0;
    for(int i=0; i<N; i++) sum+=A[i];

    vi div;
    for(int i=1; i*i<=sum; i++){
        if(sum%i == 0){
            div.push_back(i);
            if(i != sum/i) div.push_back(sum/i);
        }
    }
    int ans=0;
    for(auto d : div){
        vi tmp;
        for(int i=0; i<N; i++) tmp.push_back(A[i]%d);
        sort(all(tmp));
        vi s1(N+1, 0), s2(N+2, 0);
        for(int i=0; i<N; i++){
            s1[i+1]=s1[i]+tmp[i];
            s2[N-i]=s2[N-i+1]+(d-tmp[N-i-1]);
        }
        bool ok=false;
        for(int i=0; i<=N; i++){
            if(s1[i] == s2[i+1] && s1[i] <= K) ok=true;
        }
        if(ok) chmax(ans, d);
    }
    cout << ans << endl;
    return 0;
}