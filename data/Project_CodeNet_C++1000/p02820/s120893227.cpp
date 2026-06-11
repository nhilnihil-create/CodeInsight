#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <cstdint>
#include <sstream>
#include <map>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;
typedef long long ll;

ll ans, mx, sum, mn = 1e8, cnt;


int main(){
	ll n,k;
	cin>>n>>k;
	ll r,s,p;
	cin>>r>>s>>p;
	string t,s1;
	cin>>t;
	for(ll i=0; i<n; i++){
		if(t[i]=='r') s1+='p';
		else if(t[i]=='s') s1+='r';
		else if(t[i]=='p') s1+='s';
	}
	for(ll i=0; i<n; i++){
		if(i>=k){
			if(t[i]==t[i-k] && s1[i]==s1[i-k]){
				s1[i]=t[i];
			}
		}
	}
	for(ll i=0; i<n; i++){
		if(i>=k){
			if(t[i]!=s1[i]){
				if(s1[i]=='p') ans+=p;
				else if(s1[i]=='r') ans+=r;
				else if(s1[i]=='s') ans+=s;
			}
		}
		else {
				if(s1[i]=='p') ans+=p;
				else if(s1[i]=='r') ans+=r;
				else if(s1[i]=='s') ans+=s;
		}
	}
	cout<<ans<<endl;
}
