//I read the news today, oh boy
//About a lucky man who made the grade
 
#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz(x) ll((x).size())
#define all(v) (v).begin(),(v).end()
#define trace(x) cerr << #x << " = " << x << endl
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define For(i,a,b) for(ll i = ll(a); i < ll(b); ++i)
#define roF(i,a,b) for(ll i = ll(a); i >= ll(b); i--)
using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

const ll N=1e6;

string board[2005];
ll h, w;
vi obsx[2005], obsy[2005];

int main(){
	fastio;
	cin>>h>>w;
	For(i,0,h) cin>>board[i];
	For(i,0,h){
		obsx[i].pb(-1);
		For(j,0,w) if(board[i][j]=='#')
			obsx[i].pb(j);
		obsx[i].pb(w);
	}
	For(j,0,w){
		obsy[j].pb(-1);
		For(i,0,h) if(board[i][j]=='#'){
			obsy[j].pb(i);
		}
		obsy[j].pb(h);
	}
	ll ans = 0;
	For(i,0,h){
		int idx=0;
		For(j,0,w){
			if(board[i][j]!='#'){
				ll lo = 0, hi = sz(obsy[j]);
				while(lo+1<hi){
					ll mid = (lo+hi)>>1;
					if(obsy[j][mid]<= i) lo=mid;
					else hi=mid;
				}
				ll idy=lo;
				ll cur = obsx[i][idx+1]-obsx[i][idx]-1;
				cur += obsy[j][idy+1]-obsy[j][idy]-1;
				cur--;
				ans = max(ans,cur);
			}else idx++;
		}
	}
	cout << ans << endl;
	return 0;
}

