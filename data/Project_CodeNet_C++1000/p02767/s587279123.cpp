#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,min=10000000;
	cin>>n;
	vector<int> v(n);
	for(int i=0; i<n; i++){
		cin>>v.at(i);
	}
	for(int i=1; i<101; i++){
		int ans=0;
		for(int j=0; j<n; j++){
			ans+=(v.at(j)-i)*(v.at(j)-i);
		}
		if(min>ans) min=ans;
	}
	cout<<min<<endl;
}