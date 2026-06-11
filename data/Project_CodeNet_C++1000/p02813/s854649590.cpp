#include<bits/stdc++.h>
using namespace std;
int f(int curr,string&a){
	if(curr>=a.length()-2) return 0;
	if(a[curr]!='A') return f(curr+1,a);
	if(a[curr+1]=='B' && a[curr+2]=='C') return 1+f(curr+3,a);
	return f(curr+1,a);
}
int main(){
	int n;
	cin>>n;
	vector<int>origin(n);
	vector<int>permu_a(n);
	vector<int>permu_b(n);
	for(int i=0; i<n; i++) origin[i] = i+1;
	for(int i=0; i<n; i++) cin>>permu_a[i];
	for(int i=0; i<n; i++) cin>>permu_b[i];
	int curr = 1;
	int lexi_a=0;
	int lexi_b=0;
	do{
		bool match = true;
		for(int i=0; i<n; i++){
			if(permu_a[i]!=origin[i]) match = false;
		}
		if(match) lexi_a = curr;
		match = true;
		for(int i=0; i<n; i++){
			if(permu_b[i]!=origin[i]) match = false;
		}
		if(match) lexi_b = curr;
		curr++;
		if(lexi_a && lexi_b) break;
	}while(next_permutation(origin.begin(),origin.end()));
	cout<<abs(lexi_a-lexi_b);
}