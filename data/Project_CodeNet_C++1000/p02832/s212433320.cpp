#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define M 1000000007
 
int gcd(int a,int b){
	if(b==0){
		return(a);
	}
	return(gcd(b,a%b));
} 
 
signed main(){
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
	
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	int mp[n+1]={0};
	mp[0]=1;
	int mx=0;
	for(int i=0;i<n;i++){
		if(mp[a[i]-1]){
			mp[a[i]]=1;
			mx=max(mx,a[i]);
		}
	}
	if(mx==0){
		cout << -1 << endl;
		exit(0);
	}
	cout << n-mx;
}