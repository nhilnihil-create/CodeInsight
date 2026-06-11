#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	int n,k;
	cin>>n>>k;
	int ans = log(n)/log(k) + 1;
	cout<<ans;	
	return 0;
}