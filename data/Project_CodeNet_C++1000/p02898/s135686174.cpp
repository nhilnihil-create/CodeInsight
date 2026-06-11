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
	int n,k;
	cin>>n>>k;
	inv(a,int,n);
	int count=0;
	F(0,n,i){
		if(a[i]>=k) count++;
	}
	cout<<count;
}
int main()
{
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  //int t;cin>>t;while(t--) solve(),cout<<endl;
  solve();
}

