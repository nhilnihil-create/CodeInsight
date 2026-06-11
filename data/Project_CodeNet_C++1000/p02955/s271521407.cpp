#include <bits/stdc++.h>
#define ALL(A) (A).begin(),(A).end()
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)

const ll mod = 1e9+7;
const ll INF = -1*((1LL<<63)+1);
const int inf = -1*((1<<31)+1);

using namespace std;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n,k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n)cin >> a[i];
    ll sum = 0;
    rep(i,n)sum += a[i];
    set<ll> candidates;
    for(int i=1;i*i<= sum;i++){
        if(sum%i==0){
            candidates.insert(i);
            candidates.insert(sum/i);
        }
    }
    ll ans = 1;
    for(ll x: candidates){
        ll need;
        {//calc need
            vector<ll> r(n);
            rep(i,n)r[i] = a[i]%x;
            sort(ALL(r));
            ll B = 0;
            rep(i,n)B += x - r[i];
            ll A = 0;
            need = 1e18;
            rep(i,n){
                A += r[i];
                B -= x-r[i];
                need = min(need,max(A,B));
            }
        }
        if(need <= k)ans = max(ans,x);
    }
    cout << ans << endl;
}