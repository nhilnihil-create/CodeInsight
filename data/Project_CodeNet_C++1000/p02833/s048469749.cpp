#include <bits/stdc++.h>
 
using namespace std;
 
#define int unsigned long long
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
	int d=10;
	int ans=0;
	if(n%2!=0){
		cout << 0 << endl;
		exit(0);
	}
	while(d<=n){
		ans+=(n/d);
		d*=5;
	}
	cout << ans << endl;
}