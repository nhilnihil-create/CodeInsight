#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int main(){
	ll n;
	string s;
	cin>>n>>s;
	ll ans=0;
	for(int l=0;l<n;l++){
		vector<ll> z(n-l);
		z[0]=n-l;
		int i=1,j=0;
		string t=s.substr(l,n-l);
		while(i<n-l){
		    while(i+j<n-l&&t[j]==t[i+j])j++;
		    z[i]=j;
		    if(!j){
	        i++;
	        continue;
		    }
		    int k=1;
		    while(k<j&&k+z[k]<j){
	        z[i+k]=z[k];
	        k++;
		    }
		    i+=k;
		    j-=k;
		}
		for(ll m=1;m<n-l;m++)ans=max(ans,min(m,z[m]));
	}
	cout<<ans;
	return 0;
}
