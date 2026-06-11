#include <bits/stdc++.h>
using namespace std;

vector<int> pi;

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int p;
		cin>>p;
		pi.push_back(p);
	}
	int count=0;
	for(int j=0;j<n;j++){
		if(pi[j]!=j+1)count++;
	}
	if(count<=2)cout<<"YES";
	else cout<<"NO";
}