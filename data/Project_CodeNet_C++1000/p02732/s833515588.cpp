#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE    
		freopen("input.txt", "r", stdin);     
		freopen("output.txt", "w", stdout);
	#endif

//----------------------------------------------------//
int n;
cin>>n;
int arr[n];
map<int,int>m;
rep(i,n){
	cin>>arr[i];
	m[arr[i]]++;
}
ll total = 0;
for(auto it:m){
	ll x = it.second;
	total+=x*(x-1)/2;
}
rep(i,n){
	cout<<total - m[arr[i]] + 1<<endl;
}




 






	#ifndef ONLINE_JUDGE
   		cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif

return 0;
}

