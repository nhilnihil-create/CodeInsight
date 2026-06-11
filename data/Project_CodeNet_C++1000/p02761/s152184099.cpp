#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ii pair<int,int>
#define vi vector<int>
#define vll vector<ll>
#define vii vector<ii>

const int maxn = 1e5+10;
const int mod = 1e9+7;

using namespace std;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m,ans=0;
	cin>>n>>m;
	vector<pair<int,char>> vs(m);
	map<int,char> mp;
	for(int i=0;i<m;++i){
		cin >> vs[i].ff >> vs[i].ss;
		auto it = mp.find(vs[i].ff);
		if(it == mp.end()){
			mp[vs[i].ff] = vs[i].ss;
		}
		else if(mp[vs[i].ff] != vs[i].ss){
			ans = 1;
		}
	}
	auto it = mp.find(1);
	if(it!=mp.end() && mp[1] == '0' && n > 1)
		ans=1;
	if(ans){
		cout<<-1<<endl;
		exit(0);
	}
	if(n==1 && m==0){
		cout<<0<<endl;
		exit(0);
	}
	string res;
	for(int i=0;i<n;++i){
		auto it = mp.find(i+1);
		if(it!=mp.end()){
			res.pb(mp[i+1]);
		}
		else if(i>0){
			res.pb('0');
		}
		else
			res.pb('1');
	}
	cout<<res<<endl;
	return 0;
}