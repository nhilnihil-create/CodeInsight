//Author: Fuadul Hasan(fuadul202@gmail.com)
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N   = 2e5 + 5;

std::vector<int> dp1(110);
std::vector<int> dp2(110);

int main(){
	
	int n;
	cin>>n;
	int a[n];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}


	for(int i=1;i<=n;i++){
		dp1[i] = dp1[i-1]+a[i]; 
	}

	for(int i=n;i>=1;i--){
		dp2[i] = dp2[i+1]+a[i]; 
	}
	int mx = 1000;
	for(int i=1;i<n;i++){
		mx = min(mx,abs(dp1[i] - dp2[i+1]));
	}


	cout<<mx<<endl;


	

	return 0;
}