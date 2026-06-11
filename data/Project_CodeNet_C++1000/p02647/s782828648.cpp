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

#include <bits/stdc++.h>
#define rep(i,a,n) for(ll i = a;i < n;i++)
typedef long long ll;
using namespace std;

int main(){
    
    ll n,k;
    cin >> n >> k;
    ll a[n] = {};
    rep(i,0,n) cin >> a[i];
    ll memo = min(k, 50LL);
    
    rep(i,0,memo){
        ll b[n] = {};
        rep(j,0,n){
            ll left,right;
            left = max(0LL,j-a[j]);
            right = min(n-1,j+a[j]);
            b[left]++;
            if(right+1 < n) b[right+1]--; 
        }

        rep(j,0,n){
            if(j > 0) b[j] += b[j-1];
            a[j] = b[j];
        }
    }

    rep(i,0,n){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
