#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int n;
vector<vector<pair<int,int>>> v;

//決め打ちしたときに正直者の発言が矛盾していないかをチェックする
bool check(int bit) {
    rep(i,n) {
        for(auto p : v[i]) {
            int x = p.first; //対象の人
            int y = p.second;//0:不親切な人1:正直者
            //正直者の発言だけ見る
            if(!(bit&(1<<i))) continue;
            if(y==1 && !(bit&(1<<x))) return false; //正直者である人が実際には正直者でない
            if(y==0 && bit&(1<<x)) return false; //不親切な人が実際には不親切でない
        }
    }
    return true;
}
int main() {
    cin >> n;
    v.resize(n);
    rep(i,n) {
        int a;
        cin >> a;
        v[i].resize(a);
        rep(j,a) {
            cin >> v[i][j].first >> v[i][j].second;
            v[i][j].first--;
        }
    }
    int ans = 0;
    for(int bit = 0;bit < (1<<n);bit++) {
        if(check(bit)) {
            int cnt = 0;
            rep(i,n) {
                if(bit&(1<<i))cnt++;
            }
            ans = max(ans,cnt);
        }
    }
    cout << ans << endl;
}
