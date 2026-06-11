#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ll long long
#define all(a) (a).begin(),(a).end()
#define mk make_pair
ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=10000000000000000;
typedef unsigned long long ull;



int main(){
    int n;
    cin >> n;
    map<int,int> m;
    rep(i,n){
        int a;
        cin >> a;
        m[a]++;
    }
    vector<ll> d(n+1,0);
    for (auto it=m.begin();it!=m.end();++it){
        d[it->second]++;
    }
    ll u=0,o=0;
    vector<ll> f(n);
    rep(i,n) o+=d[i+1];
    rep(i,n){
        u+=(i+1)*d[i+1];
        o-=d[i+1];
        f[i]=(u+o*(i+1))/(i+1);
        // cout << f[i] << endl;
    }
    int ans=n;
    rep(i,n){
        while(true){
            if (ans==0) break;
            if (i+1<=f[ans-1]) break;
            ans--;
        }
        cout << ans << endl;
    }
}
