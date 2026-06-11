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
	double n;
	cin>>n;
	//cout<<ceil(double(n)/2)<<endl;
	printf("%.6f",ceil(double(n)/2)/n);
}
int main()
{
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  //int t;cin>>t;while(t--) solve(),cout<<endl;
  solve();
}

