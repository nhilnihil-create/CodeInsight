#include<bits/stdc++.h>
 
using namespace std;
#define ff first
#define ss second
#define pii pair<int, int>
#define pll pair<long long , long long>
#define pb push_back
#define ll long long
#define ld long double
#define precision(x,d) cout<<fixed<<setprecision(d)<<x
#define fill(a,b) memset((a),(b),sizeof((a)))
#define FAST ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);srand(time(NULL));
ll power(ll x,ll y,ll m){ll r=1;for(;y;y>>=1){if(y&1)r=r*x%m;x=x*x%m;}return r;}
const ll mod = 1e9 + 7;
 
int run_test(){
    int x, n;
    cin >> x >> n;
    int a[n];
    set<int> s;
    for(int i=0; i<n; i++){
        cin >> a[i];
        s.insert(a[i]);
    }
    int ab = 1000, p;
    for(int i=0; i<=101; i++){
        if(s.count(i) == 0){
            if(abs(x - i) < ab){
                ab = min(ab, abs(x - i));
                p = i;
            }
        }
    }
    cout << p;
    return 0;
}
 
int main(){
    FAST;
    ll t;
    t = 1;
 
    while(t--){
        run_test();
    }
}