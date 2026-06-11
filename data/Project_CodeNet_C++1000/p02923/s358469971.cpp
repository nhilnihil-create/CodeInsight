// AUTHOR : Kishan Srivastav
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define in freopen("input.txt", "r", stdin)
#define out freopen("output.txt", "w", stdout)
#define ios ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


int main() {
	ios
#ifndef ONLINE_JUDGE
	in;
	out;
#endif
	int n;
	cin>>n;
	ll arr[n];
	for(int i = 0 ; i < n ; i++){
		cin>>arr[i];
	}
	ll count = 0 ;
	ll ans = 0;
	for (int i = 0; i < n; i++){
		if(arr[i+1] <= arr[i]){
			count++;
    		ans = max(ans, count);;
		}else{
			count = 0;
		}
	}
	//ans = max(ans,count);
	cout<<ans<<endl;

}