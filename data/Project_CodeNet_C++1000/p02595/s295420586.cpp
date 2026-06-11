#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+233;

int main(){
	long long n,d;
	cin>>n>>d;
	long long cnt=0;
	for(int i=0;i<n;i++){
		long long x,y;
		cin>>x>>y;
		if(x*x+y*y<=d*d)cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}