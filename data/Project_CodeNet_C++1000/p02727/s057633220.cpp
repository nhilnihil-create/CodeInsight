// I look at my watch
// it say nine twenty-five
// And I think oh God
// I'm still alive
 
#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz(x) int((x).size())
#define all(v) (v).begin(),(v).end()
#define trace(x) cerr << #x << " = " << x << endl
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define For(i,a,b) for(int i = int(a); i < int(b); ++i)
#define roF(i,a,b) for(int i = int(a); i >= int(b); i--)
using namespace std;
 
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;




int main(){	
	int R,G,a,b,c;cin>>R>>G>>a>>b>>c;
	vector<ii>app;
	For(i,0,a){
		int val;cin>>val;
		app.pb({val,0});
	}
	For(i,0,b){
		int val;cin>>val;
		app.pb({val,1});
	}
	For(i,0,c){
		int val;cin>>val;
		app.pb({val,2});
	}
	sort(app.rbegin(),app.rend());
	int r=0,g=0,w=0;
	ll ans=0;
	For(i,0,sz(app)){
		if(r==R&&app[i].ss==0)continue;
		if(g==G&&app[i].ss==1)continue;
		if(app[i].ss==0)r++;
		if(app[i].ss==1)g++;
		if(app[i].ss==2)w++;
		ans+=app[i].ff;
		if(r+g+w==R+G)break;
	}
	cout<<ans<<endl;

	return 0;
}