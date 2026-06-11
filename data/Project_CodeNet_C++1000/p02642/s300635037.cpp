#include <bits/stdc++.h>
using namespace std; 

#define rep(i,b) for(long long i = 0; i < (b); i++)
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
using ll = long long;
string s;

ll lcm(ll a,ll b){
	
	return (a*b)/(__gcd(a,b));
}

void solve() 
{ 
int n;
cin>>n;
vector<int> v(n);
rep(i,n){
	cin>>v[i];
}
unordered_map<int,int> vis;
sort(all(v));
int ans=0;

for(auto i:v){
	
	for(int j=1;j*i<=v[n-1];j++)
	{
		vis[j*i]++;
	}
}
for(auto i:v){
	if(vis[i]==1){
		ans++;
	}
}
cout<<ans;
}



int main(){

		solve();
		cout<<endl;


				
}
		

	

		

 

