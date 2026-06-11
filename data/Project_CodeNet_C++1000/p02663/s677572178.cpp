#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
#define chmin(a,b) a=min(a,b)
#define chmax(a,b) a=max(a,b)

int main(){
	int a,b,c,d,k;
	cin>>a>>b>>c>>d>>k;
	a=a*60+b,c=c*60+d;
	a=c-a;
	a-=k;
	if(a<0)a=0;
	cout<<a<<endl;
}
