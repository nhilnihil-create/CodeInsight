#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define debug  freopen("in.txt","r",stdin),freopen("out.txt","w",stdout);
#define pb push_back
#define all(x) x.begin(),x.end()
#define fs first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn = 3e5+10;
const int maxM = 1e6+10;
const int inf = 0x3f3f3f3f;

int N,M,T;
int row[maxn],col[maxn];
set<pii> st;
void solve(){
	int mxrow = 0,idr = 0,mxcol = 0,idl = 0;
	for(int i =1;i<=N;i++){
		if(row[i] > mxrow){
			mxrow = row[i];
			idr = i;
		}
	}
	for(int i = 1;i<=M;i++){
		if(col[i] > mxcol){
			mxcol = col[i];
			idl = i;
		}
	}
	int ans = 0;
	for(int j = 1;j<=M;j++){
		if(st.find({idr,j}) != st.end()){
			ans = max(ans,row[idr] + col[j] - 1);
		}else{
			ans = max(ans,row[idr] + col[j]);
		}
	}
	for(int i =1;i<=N;i++){
		if(st.find({i,idl}) != st.end()){
			ans = max(ans,row[i] + col[idl] - 1);
		}else{
			ans = max(ans,row[i] + col[idl]);
		}
	}
	cout<<ans<<'\n';
}
int main(){
	// debug;
	ios;

	cin>>N>>M>>T;
	for(int i = 1;i<=T;i++){
		int x,y;cin>>x>>y;
		row[x]++;
		col[y]++;
		st.insert({x,y});
	}

	solve();
	
	return 0;
}
