# include "bits/stdc++.h"
 
using namespace std;
 
#define endl "\n"
typedef long long int ll;
#define f first
#define s second
 
#define SEND_HELP ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
inline void setPrecision(int n){cout.precision(n);}
 
//DEBUG
#define BR cerr<<endl
#define dbg(x) cerr<<(#x)<<": "<<x<<endl
#define dbgV(x) cerr<<(#x)<<": "; for(auto it: x) cerr<<it<<" "; cerr<<endl;
#define dbgS(x) cerr<<(#x)<<": "; for(auto it: x) cerr<<it<<" "; cerr<<endl;
#define dbgM(x) cerr<<(#x)<<": "; for(auto it: x) cerr<<"["<<it.f<<", "<<it.s<<"] "; cerr<<endl;
#define dbg2D(x) cerr<<(#x)<<": \n"; for(auto y: x) { for(auto it: y) cerr<<it<<" "; cerr<<endl; } cerr<<endl;
#define dbgA(x, n) cerr<<(#x)<<": "; for(int i=0;i<n;++i) cerr<<x[i]<<" "; cerr<<endl;
#define dbgVP(x) cerr<<(#x)<<": "; for(auto it: x) cerr<<"["<<it.f<<", "<<it.s<<"] "; cerr<<endl;
 
ll INF = 1e10;
int MOD = 1e9+7;

#define lcm(x, y) ((x * y)/ __gcd(x, y))

int main(){
	#ifndef ONLINE_JUDGE
        freopen("inputf.in", "r", stdin);
    #endif
    SEND_HELP

    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    ll cnt = 0;

    //till a
    -- a;
    cnt += (a / c);
    cnt += (a / d);
    cnt -= (a / lcm(c,d));

    ll tots = 0;
    //till b
    tots += (b / c);
    tots += (b / d);
    tots -= (b / lcm(c,d));

    // dbg(tots);
    // dbg(cnt);

    cout << (b - a) - (tots - cnt);

    return 0;
}

/*

*/