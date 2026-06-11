#include <bits/stdc++.h>
 
typedef long long ll;
 
using namespace std;
 
int main(){
	//freopen("input.in","r",stdin);
	//freopen("output.in","w",stdout);
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll i,j,k,n;
    cin>>n;
    vector<ll> v(n);
    ll m(0),ans(0);
    for(i=0;i<n;i++){
    	cin>>v[i];
    	m=max(v[i],m);
    	if(i){
    		ans+=m-v[i];
    	}
    }
    cout<<ans;
 
	
	
	
 
 
 
 
 
 
 
	return 0;
}