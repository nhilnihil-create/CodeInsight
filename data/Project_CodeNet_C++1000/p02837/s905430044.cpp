#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll LINF = 1e18;
const int mod = 1e9+7;

#define pi pair<int,int>
#define pl pair<lld,lld>

#define dump(x) cout << #x << " = " << (x) << endl
#define YES(n) cout << ((n) ? "YES" : "NO"  ) << endl
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl
#define SANKOU(n,a,b) cout << ((n) ? (#a) : (#b) ) << endl

#define mem0(x) memset(x,0,sizeof(x))
#define fillnum(x,n) fill(begin(x),end(x),n)
#define asort(x) sort(x.begin(),x.end())
#define dsort(x,t) sort(x.begin(),x.end(),greater<t>())
#define vuniq(x) x.erase(unique(x.begin(), x.end()), x.end())

#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)

int main() {
    ll N;
    vector<ll> x[15],y[15];
    cin >> N;
    for (int i = 0; i < N; i++) {
        ll A; cin >> A;
        for (int j = 0; j < A; j++) {
            ll X,Y; cin >> X >> Y;
            X--; 
            x[i].pb(X);
            y[i].pb(Y);
        }
    }
    ll cnt = 0;
    for (int i = 0; i < (1 << N); i++) {
        int flg[15];
        fillnum(flg,-1);
        bool ans = true;
        for (int j = 0; j < N; j++) {
            ll b = (1 << j) & i;
            if(b != 0){
                flg[j] = 1;
            } else {
                flg[j] = 0;
            }
        }
        for (int j = 0; j < N; j++) {
            if(flg[j] == 1){
                for (int k = 0; k < x[j].size(); k++) {
                    if(flg[x[j][k]] != y[j][k]){
                        ans = false;
                        break;
                    }
                }
            }
            if(ans == false){
                break;
            }
        }
        if(ans == true){
            ll c = 0;
            for (int j = 0; j < N; j++) {
                if(flg[j] == 1){
                    c++;
                }
            }
            cnt = max(cnt,c);
        }
    }
    cout << cnt << endl;
}