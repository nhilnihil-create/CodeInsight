#include <bits/stdc++.h>
#define newl "\n"
using namespace std;
using lli = long long int;
using vvint = vector <vector <int>>;
const int mod = 1e9 + 7;

const int N = 2e5 + 1;

void dfs(int s,vector <bool> &vis,vector <int> &p,vector <int> &out){
	vis[s] = 1;
	out.push_back(s);
	if(!vis[p[s]]) dfs(p[s],vis,p,out);
	return;
}

void solve(){
	int n,k;
	cin >> n >> k;
	vector <int> p(n),c(n);
	for(int i = 0;i < n;++i){
		cin >> p[i];
		--p[i];
	}
	for(int i = 0;i < n;++i){
		cin >> c[i];
	}
	lli maxx = -2e18;
	vector <bool> vis(n,0);
	for(int i = 0;i < n;++i){
		if(!vis[i]){
			vector <int> out;
			dfs(i,vis,p,out);
			lli l = out.size();
			//for(int i : out) cout << i << " ";
			//cout << newl;
			for(int i = 0;i < l;++i){
				if(k >= l){
					lli k1 = k / l;
					lli summ = 0;
					for(int j = i + 1;j < l;++j){
						summ = summ + c[out[j]];
						maxx = max(maxx,summ);
					}
					for(int j = 0;j <= i;++j){
						summ = summ + c[out[j]];
						maxx = max(maxx,summ);
					}
					if(summ <= 0){
					}
					else{
						lli maxx3 = summ * k1;
						lli pp = summ * k1;
						lli k2 = k % l;
						for(int j = i + 1;j <= min(l - 1,i + k2);++j){
							pp = pp + c[out[j]];
							maxx3 = max(maxx3,pp);
						}
						for(int j = 0;j <= max(-1ll,k2 - (l - i));++j){
							pp = pp + c[out[j]];
							maxx3 = max(maxx3,pp);
						}
						lli maxx4 = summ * (k1 - 1);
						lli pp1 = summ * (k1 - 1);
						for(int j = i + 1;j <= l - 1;++j){
							pp1 = pp1 + c[out[j]];
							maxx4 = max(maxx4,pp1);
						}
						for(int j = 0;j <= i;++j){
							pp1 = pp1 + c[out[j]];
							maxx4 = max(maxx4,pp1);
						}
						maxx3 = max(maxx3,maxx4);
						maxx = max(maxx3,maxx);
					}
				}
				else{
					lli summ = 0;
					lli maxx2 = -2e18;
					for(int j = i + 1;j <= min(l - 1ll,(lli)(i + k));++j){
						summ = summ + c[out[j]];
						maxx2 = max(maxx2,summ);
					}
					for(int j = 0;j <= max(-1ll,k - (l - i));++j){
						summ = summ + c[out[j]];
						maxx2 = max(maxx2,summ);
					}
					maxx = max(maxx2,maxx);
				}
			}
		}
	}
	cout << maxx << newl;

	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(10);
	#ifdef EXECUTE_LOCALLY
		   freopen("in.txt","r",stdin);
	#endif
	int t = 1;
	//cin >> t;
	while(t--) solve();
	#ifdef EXECUTE_LOCALLY
    	cout << setprecision(3) << "program time: " << (double)clock() / CLOCKS_PER_SEC << newl;
	#endif
	return 0;
}
