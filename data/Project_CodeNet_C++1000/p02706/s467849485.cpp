#include <bits/stdc++.h>
#define INF 1000000005
#define mod 1000000007
#define EPS 1e-10
#define rep(i,n) for(int i = 0; i < (n); ++i) /*0からn-1までのrep*/
#define rrep(i,n) for(int i = 1; i <= (n); ++i) /*1からnまでのrep*/
#define drep(i,n) for(int i = (n)-1; i >= 0; --i) /*n-1から0までのrep*/
#define srep(i,s,t) for (int i = s; i < t; ++i) /*sからt-1までのrep*/
#define each(a,b) for(auto& (a): (b)) /*よくわからん*/
#define all(v) (v).begin(),(v).end() /*全選択*/
#define sz(v) (int)(v).size() /*大きさ*/
#define zip(v) sort(all(v)),v.erase(unique(all(v)),v.end()) /*重複削除*/
#define cmx(x,y) x=max(x,y) /*最大値*/
#define cmn(x,y) x=min(x,y) /*最小値*/
#define rev(v) reverse((v).begin(),(v).end()); /*逆順*/
#define so(v) sort((v).begin(), (v).end()); /*ソート*/
#define yn {puts("Yes");}else{puts("No");} /*はい・いいえ*/
#define fi first
#define se second
#define pb push_back

using namespace std;

using ll = long long;
using P = pair<int,int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vd = vector<double>;
using vp = vector<P>;
using vs = vector<string>; 

int main() {
    int a, b,s,t;
    cin >> a >> b;
    rep(i, b) {
        cin >> t;
        a = a - t;
    }
    if (a >= 0) {
        cout << a << endl;
    }
    else {
        cout << "-1" << endl;
    }
    return 0;
}