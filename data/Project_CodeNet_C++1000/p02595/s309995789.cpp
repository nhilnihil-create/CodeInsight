#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define ull unsigned long long
#define ld long double
#define uint unsigned int
#define endl '\n'
#define fi first 
#define se second 
#define mp make_pair 
#define pb push_back 
#define eb emplace_back 
#define pll pair<long long ,long long > 
#define ppll pair < pll , pll > 
#define pd pair<int, int>
#define ppdd pair<pd, pd>
#define vd vector<int>
#define sd(x) scanf("%d",&x) 
#define sld(x) scanf("%lld",&x) 
#define deb(x) { cerr << #x << '=' << x << '\n'; }
#define tc(x) sd(x); while(x--)
#define INF 1e18 
#define eps 0.00001 
#define le length 
#define inc(il)
using namespace std;

void solve(){
    //code goes here
    int n,cnt=0;
    double d;
    cin >> n >> d;
    double x,y;
    for (int i = 1; i<=n; ++i){
        cin >> x >> y;
        double dist=sqrt(x*x+y*y);
        if (dist<=d) cnt++;
    }
    cout << cnt;
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL); 
    solve();
    return 0;
}
