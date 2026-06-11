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
    int N; cin >> N;
    vi H(N);
    for(auto &x : H) cin >> x;

    bool ans=true;
    for(int i=1; i<N; i++){
        if(H[i] < H[i-1]){
            ans=false;
            break;
        }
        if(H[i] > H[i-1]) H[i]--;
    }
    cout << (ans?"Yes":"No") << endl;
    return 0;
}