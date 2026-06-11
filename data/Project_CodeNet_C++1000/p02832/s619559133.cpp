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

int main(){
	#ifndef ONLINE_JUDGE
        freopen("inputf.in", "r", stdin);
    #endif
    SEND_HELP

    int n;
    cin >> n;
    int a[n];
   	map<int, set<int>> m;
   	bool ok = 0;
   	for(int i = 0; i < n; ++ i){
   		cin >> a[i];
   		m[a[i]].insert(i);
   		ok |= a[i] == 1;
   	}
   	if(!ok){
   		cout << -1 << endl;
   		exit(0);
   	}


   	int idx = *m[1].begin();
   	int cur = 2;
   	while(1){
   		if(m.find(cur) != m.end()){
   			auto zz = m[cur].upper_bound(idx);
   			if(zz != m[cur].end()){
   				idx = *zz;
   				++ cur;
   			}
   			else{
   				break;
   			}
   		}
   		else{
   			break;
   		}
   	}
   	// dbg(cur);
   	cout << n - cur + 1;

    return 0;
}

/*

*/