#include<bits/stdc++.h>
 
typedef long long int ll;
 
using namespace std;
 
#define MOD (ll)1000000007
 
ll arr[1000000];
 
ll func(int p)
{
	ll ans = 1;
	if(p == 0) return 1;
	for(int i = 1; i <= p; i++)
	{
		ans = ((ans%MOD) * (2%MOD))%MOD;
	}
	return ans;
} 
 
int main(){
 
    ll n;
    cin >> n;
    for(ll i = 0; i < n; i++){
        cin >> arr[i];
    }
    ll sum = 0;
    for(ll i = 0; i < 64; i++){
        ll oc = 0, zc = 0;
        for(ll j = 0; j < n; j++){
            if(arr[j]%2 == 0){
                zc++;
            }
            else{
                oc++;
            }
            arr[j] /= 2;
        }
        ll idsum = ((zc%MOD)*(oc%MOD))%MOD;
        idsum  = ((idsum%MOD) * (func(i)%MOD))%MOD;
        sum = ((sum%MOD) + (idsum%MOD))%MOD;
    }
    cout << sum;
}