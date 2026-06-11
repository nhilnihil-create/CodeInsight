#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const ll INF = 1LL<<60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;


int main(){
    int N; cin >> N;
    vector<int> a(N+1,0);
    rep(i,N+1){
        if (i==0) continue;
        cin >> a[i];
    }
    vector<int> counter(N+1,0);

    for(int i = N; i >= 1; i--){
        int cnt = 0;
        int multiple = 2;
        while(i * multiple <= N){
            cnt += counter[i*multiple];
            multiple++;
        }
        if ((cnt % 2) != a[i]){
            counter[i]++;
        }
    }

    vector<int> ans;
    rep(i,N+1){
        if (counter[i] == 1){
            ans.push_back(i);
        }
    }

    cout << ans.size() << endl;
    for (auto a : ans){
        cout << a << endl;
    }    
}