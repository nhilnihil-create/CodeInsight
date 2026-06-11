#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll h,w;
	cin>>h>>w;
	if(h==1 || w==1){
	 cout<<"1";
    }
	else if(h%2==0){
		ll ans=(h/2)*w;
		cout<<ans;
	}
	else{
		if(w%2==0){
			ll ans=(h)*(w/2);
			cout<<ans;
		}
		else{
			ll ans=(h)*(w/2)+(h+1)/2;
			cout<<ans;
		}
	}
return 0;

	
}