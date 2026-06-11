/**
 *    author: gxfireball       
**/
#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> arr;
    for(int i=0;i<n;++i){
      	int temp;
      	cin>>temp;
        arr.push_back(temp);
    }
    if(n==1){
    	cout<<0;
    	return;
    }
    sort(arr.begin(),arr.end(),greater<int>());
    
    ll sum=0,j=0;
    for(int i=0;i<n-1; ++i){
    	sum += arr[j];
    	if(i%2==0) j++;
    	
    }
    cout<<sum;

}

int main(){
    fastio;
    int t;
    t = 1;
    //cin>>t;
    while(t--){
    	solve();
    }
    return 0;
}

