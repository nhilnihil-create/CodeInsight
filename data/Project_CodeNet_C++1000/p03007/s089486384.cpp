#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,ll> PLL;
typedef pair<P,P> PP;
typedef vector<ll> VECLL;
typedef vector<P> VECP;
typedef priority_queue<P,VECP,greater<P> > PQP;
typedef priority_queue<ll, VECLL, greater<ll> > PQll;

#define rep(i,a,n) for(ll i = a;i < n;i++)   
#define rrep(i,a,n) for(ll i = n; i >= a;i--)
#define index_check(i,n) if(i > n-1 || i < 0) continue; 
#define LINF (ll)1e18
#define INF (int)1e9
#define fs first
#define sc second

int main(){
    ll n;
    cin >> n;
    vector<ll> vec;
    ll n_cnt = 0,p_cnt = 0;

    rep(i,0,n){
        ll a;
        cin >> a;
        vec.push_back(a);

        if(a < 0) n_cnt++;
        else p_cnt++;
    }
    sort(vec.begin(),vec.end(),greater<ll>());

    if(n_cnt == n){
        n_cnt--; p_cnt++;
    }
    else if(p_cnt == n){
        p_cnt--; n_cnt++;
    }

    ll ans = 0;
    rep(i,0,n) ans += ((i < p_cnt)?vec[i]:-vec[i]);
    cout << ans << endl; 

    if(p_cnt == 1){
        ll temp = vec[0];
        rep(i,0,n-1){
            cout << temp << " " << vec[i+1] << endl;
            temp -= vec[i+1];
        }
    }
    else{
        cout << vec[n-1] << " " << vec[0] << endl;
        ll temp = vec[n-1] - vec[0];
        rep(i,0,p_cnt-2){
            cout << temp << " " << vec[1+i] << endl;
            temp -= vec[1+i]; 
        }
        cout << vec[p_cnt-1] << " " << temp << endl;
        temp = vec[p_cnt-1] - temp;
        rep(i,0,n_cnt-1){
            cout << temp << " " << vec[n-2-i] << endl;
            temp -= vec[n-2-i];
        }
    }

}


