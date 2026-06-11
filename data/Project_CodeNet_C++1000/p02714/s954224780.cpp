#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <cstdint>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;
typedef long long ll;


ll ans, mx, mn, flag, sum, cnt,cntr,cntg;

ll b[10000],g[10000],r[10000];
int main(){
	ll n;
	cin>>n;
	string s;
	cin>>s;
	for(ll i=n-1; i>=0; i--){
		if(s[i]=='B') cnt++;
		else if(s[i]=='R') cntr++;
		else cntg++;
		b[i]=cnt;
		r[i]=cntr;
		g[i]=cntg;
	}
	
	for(ll i=0; i<n; i++){
		for(ll j=i+1; j<n; j++){
			if(s[i]=='R'&&s[j]=='G'){
				ll flag=j+(j-i);
				if(flag<n && s[flag]=='B') ans+=b[j]-1;
				else ans+=b[j];
			}
			//RBG
			else if(s[i]=='R'&&s[j]=='B'){
				ll flag=j+(j-i);
				if(flag<n && s[flag]=='G') ans+=g[j]-1;
				else ans+=g[j];
			}
			//BRG
			else if(s[i]=='B'&&s[j]=='R'){
				ll flag=j+(j-i);
				if(flag<n && s[flag]=='G') ans+=g[j]-1;
				else ans+=g[j];
			}
			//BGR
			else if(s[i]=='B'&&s[j]=='G'){
				ll flag=j+(j-i);
				if(flag<n && s[flag]=='R') ans+=r[j]-1;
				else ans+=r[j];
			}
			//GBR
			else if(s[i]=='G'&&s[j]=='B'){
				ll flag=j+(j-i);
				if(flag<n && s[flag]=='R') ans+=r[j]-1;
				else ans+=r[j];
			}
			//GRB
			else if(s[i]=='G'&&s[j]=='R'){
				ll flag=j+(j-i);
				if(flag<n && s[flag]=='B') ans+=b[j]-1;
				else ans+=b[j];
			}
		}
	}
	cout<<ans<<endl;
}
