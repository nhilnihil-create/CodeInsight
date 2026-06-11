#include<algorithm>
#include<bitset>
#include<cmath>
#include<cstdlib>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<string>
#include<utility>
#include<vector>

using namespace std;
 
typedef long long ll;

#define MP make_pair
#define F first
#define S second

int main(){
	ll n;
  	cin >> n;
  	vector<ll> h(n);
  	for(ll i=0;i<n;i++){
    	cin >> h[i];
    }
  	sort(h.begin(),h.end());
    ll x=h[0],y=h[n/3],z=h[2*n/3];
    if(x==0){
    	if(x==h[n-1]) cout << "Yes";
      	else if(x==h[n/3-1]&&y==h[n-1]) cout << "Yes";
      	else cout << "No"<< endl; 
    }else{
  		bool ans=true;
  		if(n%3!=0) ans=false;
  		if(x!=h[n/3-1]|| y!=h[2*n/3-1]|| z!=h[n-1]) ans=false;
  		if(((x^y)^z)!=0) ans=false;
  		if(ans){cout <<"Yes" << endl;}else{
    		cout << "No" << endl;
    	}
    }
}