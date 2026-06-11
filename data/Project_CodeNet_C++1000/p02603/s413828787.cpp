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
  
    for(ll i=1;i<n;i++){
    	if(arr[i]>arr[i-1]){
        	ll stocks=money/arr[i-1];
            money=(money%arr[i-1])+(stocks*arr[i]);
    	}
    }
 
    cout<<money<<endl;
 
	return 0;
}