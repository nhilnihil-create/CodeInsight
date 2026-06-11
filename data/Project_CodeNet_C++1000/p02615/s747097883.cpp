#include <bits/stdc++.h>
using namespace std;
# define ll  long long

 	ll mod = 998244353;
 	int arr[200001];
	int main() {

		#ifndef ONLINE_JUDGE
	        freopen("input.txt","r",stdin);
	        // freopen("output.txt","w",stdout);
	    #endif
	    ios::sync_with_stdio(false);
	    cin.tie(0);
	    cout.tie(0);
	   	int n;
	   	cin>>n;
	  	for(int i=0;i<n;i++){
	  		cin>>arr[i];
	  	}
	  	sort(arr,arr+n,greater<int>());

	  	queue<int> q;
	  	q.push(arr[0]);
	   	ll comfort=0;
	   	for(int i=1;i<n;i++){
	   		comfort+=q.front();
	   		// cout<<q.front()<<endl;
	   		q.pop();
	   		q.push(arr[i]);
	   		q.push(arr[i]);
	   	}
	   	cout<<comfort<<endl;
	}
