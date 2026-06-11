#include<bits/stdc++.h>
using namespace std;
int main(){
	int h,a;
	cin>>h>>a;
	int total = 0;
	while(a--){
		int b;
		cin>>b;
		total+=b;
	}
	if(h>total) cout<<"No";
	else cout<<"Yes";
}