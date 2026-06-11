#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a) for(i = 0 ; i < a ; i++)
#define whln(t) while(t--)
#define whlp(t) while(t++)
ll i=0,j=0;
#define md 1000000007

int main(void){
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif
   	// ll t;
   	// cin>>t;
   	// whln(t){
    ll n;
    cin>>n;
    vector<ll>v;
    
    rep(i,n){
    	ll a;
    	cin>>a;
    	v.push_back(a);
    }
    sort(v.begin(),v.end());
    ll cnt= 0,k ;
    rep(i,n)
    	rep(j,i)
 	   		rep(k,j)
 	   			if(v[i]!=v[j] && v[j]!=v[k] && (v[i]<v[k]+v[j]))
 	   				cnt++;
 	 cout<<cnt;  			

  	//}
}
//   *****  *******   !
//   *		     *    !
//   ***       *      !
//   *       *        !
//   *****  *******   !