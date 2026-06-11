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

const int maxn = 1e6+10;
const int mod = 1e9+7;

using namespace std;

set<string> nums;

char nxt[] = {'0','1','2','3','4','5','6','7','8','9'};

bool ok(string x){
	for(int i=1;i<x.size();++i){
		int previous = x[i-1]-'0';
		int current = x[i]-'0';
		if(abs(previous-current)>1)
			return false;
	}
	return true;
}

ll transform(string x){
	ll val = 0,ha=1LL;
	for(int i=x.size()-1;i>=0;--i){
		val = val + ((x[i]-'0')*ha);
		ha*=10LL;
	}
	return val;
}

bool comp(string x){
	if(x.size() > 10)
		return true;
	return transform(x) > 3234566667;
}

void generate(string num){
	if(comp(num) || nums.count(num)) return;
	//if(ok(num)) 
	nums.insert(num);
	//cout<<"num="<<num<<endl;
	for(char c='0';c<='9';++c){
		string aux = num;
		aux.pb(c);
		int previous = num.back()-'0';
		int current = c-'0';
		//cout<<previous<<" "<<current<<endl;
		if(abs(previous-current)>1){
			string go = num;
			int nx = (go.back()+1)-'0';
			int nnx = (go[go.size()-2]-'0');
			if(go.back()+1 <= '9' && abs(nx-nnx)<=1){
				go.back()++;
				generate(go);
			}
		}
		else
			generate(aux);
	}
	return;
}

void solve(){
	int n;
	cin>>n;
	generate("1");
	generate("2");
	generate("3");
	generate("4");
	generate("5");
	generate("6");
	generate("7");
	generate("8");
	generate("9");
	vector<ll>ans;
	for(string x:nums){
		ans.pb(transform(x));
	}
	sort(all(ans));
	cout<<ans[n-1]<<endl;
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