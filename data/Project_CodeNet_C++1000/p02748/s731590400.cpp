#include <bits/stdc++.h>
#define ll unsigned long long 
#define vec vector<ll>
using namespace std;
int main(){
	ll a,b,m;
	cin>>a>>b>>m;
	vec ref,ov;
	while(a--){
		ll in;
		cin>>in;
		ref.push_back(in);
	}
	while(b--){
		ll in;
		cin>>in;
		ov.push_back(in);
	}

	ll x = *min_element(ref.begin(),ref.end());
	ll y = *min_element(ov.begin(),ov.end());

	ll Min = x+y ;
	ll total = 0;
	while(m--){
		ll ai,bi,ci;
		cin>>ai>>bi>>ci;
		ai--;bi--;
		total = ref[ai] + ov[bi] - ci;
		//ll tmin = ref[0]+ov[0];

		if(total<Min){
			Min = total;	
		} 
		//else if(total<Min)Min = total;


	}
	cout<<Min<<endl;

}