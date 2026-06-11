# include "bits/stdc++.h"
 
using namespace std;
 
#define endl "\n"
typedef long long int ll;
#define f first
#define s second
 
inline void fastio(){ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);}
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

int n, k;
ll r, s, p;
string t;

inline bool win(int x, char s){
	if(x == 0){
		if(s == 's')
			return 1;
		else
			return 0;
	}else if(x == 1){
		if(s == 'r')
			return 1;
		else
			return 0;
	}
	else{
		if(s == 'p')
			return 1;
		else
			return 0;
	}
}

ll formdp(vector<int> a){
	int N = a.size();
	ll dp[N][3];
	ll score[] = {r, p , s};
	//0 for rock, 1 for paper, 2 for scissors
	dp[0][0] = win(0, t[a[0]]) ? score[0] : 0;
	dp[0][1] = win(1, t[a[0]]) ? score[1] : 0;
	dp[0][2] = win(2, t[a[0]]) ? score[2] : 0;

	for(int i = 1; i < N; ++ i){
		dp[i][0] = (win(0, t[a[i]]) ? score[0] : 0) + max(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = (win(1, t[a[i]]) ? score[1] : 0) + max(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] = (win(2, t[a[i]]) ? score[2] : 0) + max(dp[i - 1][0], dp[i - 1][1]);
	}

	return max(dp[N - 1][0], max(dp[N - 1][1], dp[N - 1][2]));
}


int main(){
	#ifndef ONLINE_JUDGE
        freopen("inputf.in", "r", stdin);
    #endif
    fastio();

    cin >> n >> k >> r >> s >> p >> t;

    vector<vector<int>> groups;
    set<int> keep;
    for(int i = 0; i < n; ++ i)
    	keep.insert(i);
    while(!keep.empty()){
    	int cur = *keep.begin();
    	vector<int> temp;
    	while(cur < n){
    		temp.push_back(cur);
    		keep.erase(cur);
    		cur += k;
    	}
    	groups.push_back(temp);
    }
    ll ans = 0;
    for(auto grp : groups){
    	ans += formdp(grp);
    }
    cout << ans;
    return 0;
}

/*

*/