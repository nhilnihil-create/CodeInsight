#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>pi;
const int MAXN=100005;
const int MOD=1000000007;

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define DEC(i,a,b) for(int i=(a);i>=(b);i--)
#define fst first
#define snd second
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define db(x) cerr<<#x<<" = "<<x<<"\n"
#define LOW(v,x) (lower_bound(all(v),(x))-(v).begin())
#define UP(v,x) (upper_bound(all(v),(x))-(v).begin())

int maxchar(string x){
	int tmp=0;
	for (auto c:x){
		tmp = max(tmp, (int) c-'a');
	}
	return tmp;
}
main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N;cin>>N;
	set<string> S;
	S.insert("a");
	FOR(i,2,N){
		set<string> newS;
		for(auto j:S){
			FOR(i,0,maxchar(j)+1){
				char c='a'+i;
				string k=j+c;
				newS.insert(k);
			}
		}
		swap(S,newS);
	}
	for(auto i:S) cout<<i<<"\n";
}
