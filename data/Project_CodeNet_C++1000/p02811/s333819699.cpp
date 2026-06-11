#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a) for(i = 0 ; i < a ; i++)
#define whln(t) while(t--)
#define whlp(t) while(t++)
ll i=0,j=0;
ll com(string a,string b,ll k){
	bool f = true ;
	rep(i,k)
		if(a[i]==b[i])
			f = false ;
	return 	f ;
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
	 ll k,x ;

	 cin>>k>>x;
	 if(k*500>=x)
	 	cout<<"Yes\n";
	 else
	 	cout<<"No\n";




		
	return 0 ;
	 // }
		
}
//   *****  *******   !
//   *		     *    !
//   ***       *      !
//   *       *        !
//   *****  *******   !