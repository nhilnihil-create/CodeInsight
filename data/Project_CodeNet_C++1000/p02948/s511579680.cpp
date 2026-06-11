#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template <class T> inline bool chmin(T &a, T b) {if (a > b){a = b;return true;}return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b){a = b;return true;}return false;}

const int NM = 1e5+1;
vector<int> ab[NM];

//abc137_d
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;cin>>n>>m;
    rep(i,n){
        int a,b;cin>>a>>b;
        ab[a].push_back(b);
    }
    priority_queue<int> pq;
    ll ans = 0;
    for(int i=m-1; i>=0; i--){
        // i日目=(m-i)日で金がもらえる仕事が可能
        vector<int> t = ab[m-i];
        for(int u : t){
            pq.push(u);
        }
        if(!pq.empty()){
            ans += (ll)pq.top(); pq.pop();
        }
    }
    cout<<ans<<endl;
}