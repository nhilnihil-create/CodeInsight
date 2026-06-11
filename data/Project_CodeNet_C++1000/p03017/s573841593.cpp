#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i,n) for(ll i=0;i<n;i++)

int main(){
	int n;cin>>n;
	int a,b,c,d;cin>>a>>b>>c>>d;
	string s;cin>>s;
	s='#'+s+'#';

	//b,c,dの位置関係がわからない
	//b<c<d or c<b<d or b<d<c
	bool chk=1;
	if(c==d) chk=0;
	else {
		for(int i=a;i<=max(c,d)-1;i++){
			if(s[i]=='#'&&s[i+1]=='#') chk=0;
		}
		if(c>d){
			bool chk2=1;
			for(int i=b;i<=d;i++){
				if(s[i-1]=='.'&&s[i]=='.'&&s[i+1]=='.'){
					chk2=0;
				}
			}
			if(chk2) chk=0;
		}
	}
	if(chk) cout<<"Yes"<<"\n";
	else cout<<"No"<<"\n";
}