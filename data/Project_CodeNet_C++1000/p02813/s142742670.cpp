#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a) for(i = 0 ; i < a ; i++)
#define whln(t) while(t--)
#define whlp(t) while(t++)
ll i=0,j=0;
ll fac(ll n){
	if(n==1||n==0)
		return 1 ;
	else
		return n*fac((n-1));
}
ll posi(ll n,vector<ll> &a,vector<ll> &b){
	// cerr<<"n="<<n<<", ";
	if(n==1)
		return 0 ;
	else{

		ll x =0;
		ll cnt = 0;
		ll tmp = a[((int)a.size())-n];
		for(ll idx=((int)a.size())-n; idx < a.size(); idx++)
			if(a[idx] < tmp)
				cnt++;
		x+=fac(n-1)*(cnt);
		// rep(i,a.size()){
		// 	cerr<<"i="<<i<<", ";
		// 	if(==b[i]){
		// 		x+=fac(n-1)*(i);
		// 		break;
		// 	}
		// }
		// cerr<<"x="<<x<<endl;
		return x + posi(n-1,a,b) ;
	}
}


int main(void){
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif
	// int t ;
	// cin>>t;
	// whln(t){
	ll n ;
	cin>>n;
	vector<ll>a(n),b(n),c(n);
	rep(i,n){
		cin>>a[i];
		c[i]=a[i];
	}
	rep(i,n)
		cin>>b[i];
	sort(c.begin(),c.end());

	// cerr<<posi(n,a,c)<<endl;
	cout<<abs(posi(n,a,c)-posi(n,b,c))<<"\n";
		
}
//   *****  *******   !
//   *		     *    !
//   ***       *      !
//   *       *        !
//   *****  *******   !