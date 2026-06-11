//       Author: Mostafa Mounir Shehab
 
#include <bits/stdc++.h>
using namespace std;
 
#define PI  acos(-1)
#define EPS (1e-10)
#define endl "\n"
#define SZ(v) (int)(v.size())
#define IO ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL), cerr.tie(NULL);
typedef long long ll;
typedef long double ld;
 
 
 
ll MOD=1e9 + 7;
ll OO=1e9 + 1;
const int N=1e6 + 10,M=20;
int fr[N];


int n,m,k,T;
int a,b,c;
int l,r,mid;
string str;

vector<pair<int,int>> vec;
set<pair<int,int>> st;
map<int,vector<int>> mp;


int main(){
	IO
	//freopen("in.txt","r",stdin);
	cin>>n>>m>>k;
	for(int i=0;i<k;++i){
		cin>>a>>b;
		vec.push_back({a,b});
		if(!fr[b])
			st.insert({0,b});
		st.erase({fr[b],b});
		fr[b]++;
		st.insert({fr[b],b});
	}
	
	
	for(auto &it:vec)
		mp[it.first].push_back(it.second);
	
	int ans = 0;
	for(auto &it:mp){
		for(int &i:it.second){
			st.erase({fr[i],i});
			--fr[i];
			st.insert({fr[i],i});
		}
		
		ans = max(ans,SZ(it.second) + (*st.rbegin()).first);
		
		for(int &i:it.second){
			st.erase({fr[i],i});
			++fr[i];
			st.insert({fr[i],i});
		}
	}
	
	cout<<ans<<endl;

}

 