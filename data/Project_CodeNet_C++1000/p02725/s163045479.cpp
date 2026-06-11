#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll k,n;
    cin>>k>>n;
    ll arr[n];
    for(ll i=0;i<n;++i){
    	cin>>arr[i];
	}
	ll minans = k;
	ll tempans = arr[n-1] - arr[0];
	minans = tempans;
	for(int i=1;i<n;++i){
		tempans =  k - arr[i] + arr[i-1];
		minans = min(minans, tempans);
	}
  cout<<minans<<endl;

return 0;
}

