#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
 
typedef long long ll;
typedef vector<int> vi;
typedef unsigned long ul;
typedef vector<ll> vl;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef set<int> si;
typedef multiset<int> mi;
 
const ll INF = 1e18;
const int MOD = 1e9+7;
 
int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	//ofstream cout ("fileName.out");
	//ifstream cin ("fileName.in");
	
	int H, W, K, black=0;
	cin>>H>>W>>K;
	
	vector<vector<char>> v(H, vector<char>(W));
	
	for(int j=0; j<H; ++j) {
		string row;
		cin>>row;
		for(int i=0; i<W; ++i) {
			v[j][i]=row[i];
			if(row[i]=='#') ++black;
		}
	}
	
	if(black<K) cout<<"0\n";
	else {
		
		int ans=0;
		
		for(int j=0; j<(1<<H); ++j) {
			for(int i=0; i<(1<<W); ++i) {
				
				int cnt=0;
				
				for(int r=0; r<H; ++r) {
					for(int c=0; c<W; ++c) {
						if(j&(1<<r) || i&(1<<c)) continue;
						else if(v[r][c]=='#') ++cnt;
					}
				}
				
				if(cnt==K) ++ans;
			} 
		}
		
		cout<<ans<<"\n";
	}
	
	return 0;
}
