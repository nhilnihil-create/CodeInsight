#include <bits/stdc++.h>
#define ll long long int
#define inv(name,Type,size) vector<Type> name(size);for(int index=0;index<n;index++) cin>>name[index];
#define F(a,n,i) for(int i=a;i<n;i++)
#define pb push_back
#define endl "\n"
#define mod 10000000007
#define modpro 99824435
using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<pair<int,int>> v(n);
	F(0,n,i){
		cin>>v[i].first;
		v[i].second=i+1;
	}
	sort(v.begin(),v.end());
	F(0,n,i){
		cout<<v[i].second<<" ";
	}
}
int main()
{
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  //int t;cin>>t;while(t--) solve(),cout<<endl;
  solve();
}

