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

void solve(){
	list<char> lst;
	string s;
	cin>>s;
	for(int c:s) lst.pb(c);
	int q,rev=0;
	cin>>q;
	while(q--){
		int t;
		cin>>t;
		if(t==1)
			rev^=1;
		else{
			int pos; char c;
			cin>>pos>>c;
			if(pos==1 && !rev)
				lst.push_front(c);
			else if(pos==1 && rev)
				lst.pb(c);
			else if(pos==2 && !rev)
				lst.pb(c);
			else
				lst.push_front(c);
		}
	}
	if(rev)
		reverse(all(lst));
	for(char c:lst)
		cout<<c;
	cout<<endl;
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
	return 0;
}