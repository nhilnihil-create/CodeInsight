#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,int> pdi;
typedef pair<double,double> pdd;
typedef pair<double,ll> pdl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<pdd> vdd;
typedef vector<pdi> vdi;
typedef vector<pdl> vdl;
typedef vector<string> vs;
#define fi first
#define se second
const ll INFLL=LLONG_MAX;
const int INF=INT_MAX;
const ll MAXLL=0x3f3f3f3f3f3f3f3f;
const int MAX=0x3f3f3f3f;
const ll MOD=1000000007;
const ll mod=998244353;
#define eb emplace_back
#define emp emplace
#define mp(a,b) make_pair(a,b)
template<class T> using min_heap=priority_queue<T,vector<T>,greater<T> >;
template<class T>
void sort(vector<T>& v){
	sort(v.begin(),v.end());
}
template <class T, class U>
void sort(vector<T>& v,U func){
	sort(v.begin(),v.end(),func);
}
template<class T>
void rsort(vector<T>& v){
	sort(v.rbegin(),v.rend());
}
template <class T>
int lb_index(vector<T>& v,T k){
	return lower_bound(v.begin(),v.end(),k)-v.begin();
}
template <class T>
int ub_index(vector<T>& v,T k){
	return upper_bound(v.begin(),v.end(),k)-v.begin();
}
template<class T>
bool is_sorted(vector<T>& v){
	return is_sorted(v.begin(),v.end());
}
template<class T>
bool sorted(vector<T>& v){
	return is_sorted(v);
}
void precompute(){

	return;
}
void solve(){
	deque<char>d;
	string s;
	cin>>s;
	bool flipped=0;
	for(int i=0;i<s.size();i++){
		d.push_back(s[i]);
	}
	int q;
	cin>>q;
	while(q--){
		int t;
		cin>>t;
		if(t==1)flipped=!flipped;
		else{
			char c;
			cin>>t>>c;
			if(t==1){
				if(flipped){
					d.push_back(c);
				}
				else d.push_front(c);
			}
			else{
				if(!flipped){
					d.push_back(c);
				}
				else d.push_front(c);
			}
		}
	}
	if(flipped){
		while(!d.empty()){
			cout<<d.back();
			d.pop_back();
		}
	}
	else{
		while(!d.empty()){
			cout<<d.front();
			d.pop_front();
		}
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);
	int numberofsubtestcases=1;
//	cin>>numberofsubtestcases;
	precompute();
	for(int looping=1;looping<=numberofsubtestcases;looping++){
//		cout<<"Case #"<<looping<<": ";
		solve();
	}
	return 0;
}


