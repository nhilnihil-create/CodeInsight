#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = n-1; i >= 0; i--)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VP = vector<P>;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

int main(){
    int k;
    cin >> k;
    queue<ll> q;
    VL ans;
    for(int i = 1; i < 10; i++){
        q.push(i);
        ans.push_back(i);
    } 
    ll cnt = q.size();
    while(cnt < k){
        ll x = q.front(); q.pop();
        ll d = x % 10;
        x *= 10;
        if (d != 0) {
            q.push(x + (d-1));
            ans.push_back(x + (d-1));
            cnt++;
        }
        q.push(x + d);
        ans.push_back(x + d);
        cnt++;
        if (d != 9){
            q.push(x + (d+1));
            ans.push_back(x + (d+1));
            cnt++;
        }
    }
    cout << ans[k-1] << endl;
    return 0;
}