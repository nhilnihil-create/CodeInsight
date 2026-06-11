#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define inv(name,Type,size) vector<Type> name(size);for(int index=0;index<n;index++) cin>>name[index];
#define F(a,n,i) for(int i=a;i<n;i++)
#define pb push_back
#define endl "\n"
#define mod 10000000007
#define modpro 99824435

const int d4i[4]={-1,0,1,0},d4j[4]={0,1,0,-1};
const int d8i[8]={-1,-1,0,1,1,1,0,-1},d8j[8]={0,1,1,1,0,-1,-1,-1};


void solve(){
	int l,r,d;
	cin>>l>>r>>d;
	int ans=0;
	F(l,r+1,i){
		if(i%d == 0) ans++;
	}
	cout<<ans;
}

int main()
{
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  //int t;cin>>t;while(t--) solve(),cout<<endl;
  solve();
}

