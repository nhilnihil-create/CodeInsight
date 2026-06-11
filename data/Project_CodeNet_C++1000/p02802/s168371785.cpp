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
    ll N,M;
    bool flg[100010];
    ll cnt[100010];
    mem0(cnt);
    mem0(flg);
    ll ACcnt = 0,WAcnt = 0;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        ll p; string s;
        cin >> p >> s;
        p--;
        if(s == "AC"){
            if(flg[p] == false){
                flg[p] = true;
                ACcnt++;
                WAcnt += cnt[p];
            }
        } else {
            if(flg[p] == false){
                cnt[p]++;
            }
        }
    }
    cout << ACcnt << " " << WAcnt << endl;
}