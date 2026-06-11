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
    string S;
    cin >> S;
    ll Rcnt = 0,Lcnt = 0;
    vector<ll> cnt;
    for (int i = 0; i < S.size(); i++) {
        if(S[i] == 'R'){
            Rcnt++;
            if(Lcnt != 0){
                cnt.pb(Lcnt);
                Lcnt = 0;
            }
        } else {
            Lcnt++;
            if(Rcnt != 0){
                cnt.pb(Rcnt);
                Rcnt = 0;
            }
        }
    }
    cnt.pb(Lcnt);
    vector<ll> ans;
    for (int i = 0; i < cnt.size(); i++) {
        if(i % 2 == 1){
            ll c = 0;
            c += cnt[i-1]/2 + cnt[i]/2;
            if(cnt[i] % 2 == 1){
                c++;
            }
            ans.pb(c);
        }
        for (int j = 0; j < cnt[i]-1; j++) {
            ans.pb(0);
        }
        if(i % 2 == 0){
            ll c = 0;
            c += cnt[i]/2 + cnt[i+1]/2;
            if(cnt[i] % 2 == 1){
                c++;
            }
            ans.pb(c);
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if(i == ans.size()-1){
            cout << endl;
        } else {
            cout << " ";
        }
    }
}