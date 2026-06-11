#include<algorithm>
#include<bitset>
#include<cmath>
#include<cstdlib>
#include<iomanip>
#include<iostream>
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
	ll n,k;
    cin >> n>>k;
    vector<ll> a(n);
  	for(ll i=0;i<n;i++){
    cin>>a[i];
    }
    ll ans=0,cnt=0,fir=0;
    ll tmp=(k*(k-1)/2)%1000000007;
  	for(ll i=0;i<n;i++){
        cnt=0;fir=0;
    	for(ll j=0;j<n;j++){
        	if(a[j]<a[i]){
              	cnt++;
            	if(i<j)fir++;
            }
        }
        ans = (ans+cnt*tmp)%1000000007;
        ans = (ans+fir*k)%1000000007;
    }
    cout << ans << endl;
}