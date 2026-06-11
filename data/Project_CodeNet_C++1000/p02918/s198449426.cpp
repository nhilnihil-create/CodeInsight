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

    //REV AND FLIP

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    string t(1, s[0]);
    char stay = s[0];
    int i = 1;
    int mv = 0;
    int len = 0;
    while(i < n && mv < k){
    	if(s[i] == stay){
    		if(len != 0)
    			++ mv;
    		string temp(len + 1, stay);
    		t += temp;
    		len = 0;
    	}
    	else{
    		++ len;
    	}
    	++ i;
    }

    if(mv != k){
    	++ mv;
    	string temp(len + 1, stay);
    	t += temp;
    }

    while(i < n){
    	string temp(1, s[i]);
    	t += temp;
    	++ i;
    }

    dbg(t);

    char prev = t[0];
    len = 1;
    int ans = 0;
    for(i = 1; i < n; ++i){
    	if(t[i] == prev){
    		++ len;
    	}
    	else{
    		ans += (len - 1);
    		prev = t[i];
    		len = 1;
    	}
    }
    ans += (len - 1);
    cout << ans;
    return 0;
}

/*

*/