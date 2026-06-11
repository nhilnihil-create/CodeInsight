# include "bits/stdc++.h"
 
using namespace std;
 
#define endl "\n"
typedef long long int ll;
#define f first
#define s second
 
inline void fastio(){ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);}
inline void setPrecision(int n){cout.precision(n);}
 
//DEBUG
#define dbg(x) cerr<<(#x)<<": "<<x<<endl
#define dbgV(x) cerr<<(#x)<<": "; for(auto it: x) cerr<<it<<" "; cerr<<endl;
#define dbgS(x) cerr<<(#x)<<": "; for(auto it: x) cerr<<it<<" "; cerr<<endl;
#define dbgM(x) cerr<<(#x)<<": "; for(auto it: x) cerr<<"["<<it.f<<", "<<it.s<<"] "; cerr<<endl;
#define dbg2D(x) cerr<<(#x)<<": \n"; for(auto y: x) { for(auto it: y) cerr<<it<<" "; cerr<<endl; } cerr<<endl;
#define dbgA(x, n) cerr<<(#x)<<": "; for(int i=0;i<n;++i) cerr<<x[i]<<" "; cerr<<endl;
#define dbgVP(x) cerr<<(#x)<<": "; for(auto it: x) cerr<<"["<<it.f<<", "<<it.s<<"] "; cerr<<endl;
 
ll INF = 1e10;
int MOD = 1e9+7;

int main(){
    fastio();

    int n;
    cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; ++i)
    	cin >> a[i];
    int b[n + 1];
    for(int i = 1; i <= n; ++i)
    	cin >> b[i];
    int c[n];
    for(int i = 1; i < n; ++i)
    	cin >> c[i];

    int sum = 0;
    int prev = -2;
    for(int i = 1; i <= n; ++i){
    	dbg(prev);
    	sum += (b[a[i]]);
    	if(prev + 1 == a[i]){
    		sum += c[a[i] - 1];
    	}
    	prev = a[i];
    }

    cout << sum;
    return 0;
}

/*

*/