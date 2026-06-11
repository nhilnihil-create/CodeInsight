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
  	ll n,sum=0;
  	cin>>n;
  	map<ll,ll>m;
  	vector<ll>a(n);
  	rep(i,n){
  		cin>>a[i];
  		sum+=a[i];
  		m[a[i]]++;
  	}
  	ll q,k;
  	cin>>q ;
  	vector<pair<ll,ll>>v(q);
  	rep(i,q){
  		cin>>v[i].first>>v[i].second;
  		sum = sum - m[v[i].first]*(v[i].first -v[i].second);
  		k  = m[v[i].first];
  		m[v[i].first]= 0;
  		m[v[i].second]+= k ;
  		cout<<sum<<"\n";
  	}

}
//   *****  *******   !
//   *		     *    !
//   ***       *      !
//   *       *        !
//   *****  *******   !