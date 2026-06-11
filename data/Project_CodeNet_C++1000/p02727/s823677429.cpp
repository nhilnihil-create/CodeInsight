
#include <bits/stdc++.h>
using namespace std;
 
#define endl "\n"
#define int long long
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
#define mem(a,b) memset((a),(b),sizeof (a))
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define INF long long(1e18)
#define MOD 1000000007


void solve(){
	int x,y,a,b,c,sum=0;
	cin>>x>>y>>a>>b>>c;
	int red[a],green[b],cl[c];
	for(int i=0;i<a;i++){
		cin>>red[i];
	}
	for(int i=0;i<b;i++){
		cin>>green[i];
	}
	for(int i=0;i<c;i++){
		cin>>cl[i];
	}
	sort(red,red+a,greater<int>());
	sort(green,green+b,greater<int>());
	sort(cl,cl+c,greater<int>());
	vector<int> ans;
	for(int i=0;i<a&&i<x;i++){
		ans.pb(red[i]);
	}
	for(int i=0;i<b&&i<y;i++){
		ans.pb(green[i]);
	}	
	for(int i=0;i<c;i++){
		ans.pb(cl[i]);
	}
	sort(ans.rbegin(),ans.rend());
	for(int i=0;i<x+y;i++){
		sum+=ans[i];
	}
	cout<<sum<<endl;
}

int32_t main(){
    int t=1;
    while(t--)
        solve();
    return 0;
}


