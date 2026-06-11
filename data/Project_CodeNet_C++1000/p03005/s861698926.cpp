#include <bits/stdc++.h>
typedef long long int ll;
using namespace std; 
ll N = pow(10,10);
int main(){
	ios_base::sync_with_stdio(false);  
	cin.tie(NULL);
	int n,k;cin>>n>>k;
	int ans=0;
	if(k==1){
		ans =0;
	}
	else{
		ans = n-k;
	}
	cout<<ans<<endl;
}