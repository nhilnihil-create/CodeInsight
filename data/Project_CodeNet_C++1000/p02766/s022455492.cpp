#include <bits/stdc++.h>
#define ll long long 
#include<vector>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int mod=1e9+7;
int main(){
	IOS;
	int n,k;
	cin>>n>>k;
	int ans=0;
	while(n!=0){
		n/=k;
		ans++;
	}
	cout<<ans;
}