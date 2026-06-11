#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a) for(i = 0 ; i < a ; i++)
#define whln(t) while(t--)
#define whlp(t) while(t++)
ll i=0,j=0;


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
  	ll n;
  	cin>>n;
  	vector<ll>v(n);
  	set<ll>s ;

  	rep(i,n){
  		cin>>v[i];
  		s.insert(v[i]);
  	}

  	if(s.size()!=v.size())
  		cout<<"NO\n";
  	else
  		cout<<"YES\n";
  	
}
//   *****  *******   !
//   *		     *    !
//   ***       *      !
//   *       *        !
//   *****  *******   !