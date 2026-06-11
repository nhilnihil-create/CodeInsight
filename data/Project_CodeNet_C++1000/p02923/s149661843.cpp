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
const int MOD=1e9+7;

template<typename T> bool chmax(T &a,const T b){if(a < b){a=b; return true;} return false;}
template<typename T> bool chmin(T &a,const T b){if(a > b){a=b; return true;} return false;}

int main(){
    int n; cin >> n;
    vi h(n);
    for(auto &x: h) cin >> x;
    int ans=0;
    for(int i=0; i<n; i++){
        int pos=i+1;
        while(pos < n && h[pos] <= h[pos-1]){
            pos++;
        }
        ans=max(ans, pos-i-1);
        i=pos-1;
    }
    cout << ans << endl;
    return 0;
}