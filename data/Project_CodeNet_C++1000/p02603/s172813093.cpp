// D - Road to Millionaire
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,arr[100];

int main(){
	cin >> n;
	for(int i=0;i<n;i++) cin >> arr[i];
	ll ans = 1000,s=0;
	for(int i=0;i<n-1;i++){
		if(arr[i] < arr[i+1]){
			s   += ans/arr[i];
			ans  = ans%arr[i];
		}else if(arr[i] > arr[i+1]){
			ans += arr[i] * s;
			s   = 0;   
		}
		//cout << i << " " << ans << " " << s <<  endl;
	}
	ans += s * arr[n-1];
	cout << max(1000ll,ans) << endl;
}
