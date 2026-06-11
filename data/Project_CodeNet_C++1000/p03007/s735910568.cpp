#include <bits/stdc++.h>
using namespace std;
#define mp       make_pair
#define pb       push_back
#define all(x)   (x).begin(),(x).end()
#define YES() printf("YES\n")
#define NO() printf("NO\n")
#define Yes() printf("Yes\n")
#define No() printf("No\n")
#define in(x,y,h,w) x >= 0 && x < h && y >= 0 && y < w

#define int long long
//using ll = long long;
using P = pair<int,int>;

template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }
 
const int INF=1e+18;
const double EPS=1e-9;
const int MOD=1000000007;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

signed main(){
	int n,a[100010],mi = INF,mii,ma = -INF,mai;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> a[i];
		if(mi > a[i]){
			mi = a[i];
			mii = i;
		}
		if(ma < a[i]){
			ma = a[i];
			mai = i;
		}
	}
	if(mii == mai) mai = (mai + 1) % n;
	vector<P> sousa;
	if(mi >= 0){
		for(int i = 0;i < n;i++){
			if(i != mii && i != mai){
				sousa.emplace_back(a[mii],a[i]);
				a[mii] -= a[i];
			}
		}
		sousa.emplace_back(a[mai],a[mii]);
		a[mai] -= a[mii];
	}else if(ma <= 0){
		for(int i = 0;i < n;i++){
			if(i != mai){
				sousa.emplace_back(a[mai],a[i]);
				a[mai] -= a[i];
			}
		}
	}else{
		for(int i = 0;i < n;i++){
			if(a[i] >= 0 && i != mai){
				sousa.emplace_back(a[mii],a[i]);
				a[mii] -= a[i];
			}
		}
		sousa.emplace_back(a[mai],a[mii]);
		a[mai] -= a[mii];
		for(int i = 0;i < n;i++){
			if(a[i] < 0 && i != mii){
				sousa.emplace_back(a[mai],a[i]);
				a[mai] -= a[i];
			}
		}
	}
	cout << a[mai] << endl;
	for(P p : sousa) cout << p.first << " " << p.second << endl;
}