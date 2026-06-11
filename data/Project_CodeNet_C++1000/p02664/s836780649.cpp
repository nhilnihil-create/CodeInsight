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
	string s;
	cin>>s;
	rep(i,s.size()){
		if(s[i]=='?')s[i]='D';
	}
	cout<<s<<endl;
}
