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

    int b[n - 1];
    for(int i = 0; i < n - 1; ++i)
    	cin >> b[i];

    int a[n];
    a[n - 1] = b[n - 2];
    int s = b[n - 2];
    for(int i = n - 2; i >= 1; -- i){
    	if(b[i] >= b[i - 1]){
    		a[i] = b[i - 1];
    	}
    	else{
    		a[i] = b[i];
    	}
    	s += a[i];
    }
    cout << s + b[0];

    return 0;
}

/*

*/
