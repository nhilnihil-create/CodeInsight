#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	int h,n;
	cin>>h>>n;
	int k;
	for (int i = 0; i<n; i++){
		cin>>k;
		h-=k;
	}
	if (h > 0){
		cout<<"No";
	}
	else{
		cout<<"Yes";
	}
	return 0;
}