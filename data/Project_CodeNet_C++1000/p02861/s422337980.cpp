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

double calc_dist(P pos1, P pos2){
    return sqrt(pow(pos1.fs - pos2.fs, 2) + pow(pos1.sc - pos2.sc,2));
}

int main(){ 
    ll n;
    cin >> n;
    double ans = 0;
    ll cnt = 0;
    P pos[n];
    ll array[n] = {};

    rep(i,0,n){
        ll a,b;
        cin >> a >> b;
        pos[i].fs = a;
        pos[i].sc = b;
        array[i] = i;
    }

    do{
        rep(i,0,n-1){
            ans += calc_dist(pos[array[i]],pos[array[i+1]]);
        }
        cnt++;

    }while(next_permutation(array,array+n));


    cout << setprecision(10) << ans / (ll)cnt << endl;
    return 0;
}
