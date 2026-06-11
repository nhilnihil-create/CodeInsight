#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n{0};
    cin>>n;

    ll arr[n];
    for(ll i=0;i<n;i++)
    	cin>>arr[i];

    ll money=1000;
    ll start{0};   //represents starting-index(first index) of the increasing subarrays  
    
    for(ll i=0;i<n-1;i++){
    	if(arr[i+1]>arr[i]){
        	continue;
    	}
        else{
            ll stocks=money/arr[start];
            money=(money%arr[start])+(stocks*arr[i]);
            start=i+1;
        }
    }
    if(start!=n-1){
        ll stocks=money/arr[start];
        money=(money%arr[start])+(stocks*arr[n-1]);
    }

    cout<<money<<endl;

	return 0;
}

