#include <bits/stdc++.h>
using namespace std;
typedef  long long  ll;

	
	int main() {

		#ifndef ONLINE_JUDGE
	        freopen("input.txt","r",stdin);
	        // freopen("output.txt","w",stdout);
	    #endif
	    ios::sync_with_stdio(false);
	    cin.tie(0);
	    cout.tie(0);
	   
	  	ll a,b,c,d;
	  	cin>>a>>b>>c>>d;
	  	cout<<max(a*c,max(a*d,max(b*c,b*d)));
	    return 0;
}



	

