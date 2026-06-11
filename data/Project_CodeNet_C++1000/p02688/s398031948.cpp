#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	set<int>s;
	while(k--){
		int d,x;
		cin>>d;
		for(int i=0;i<d;i++)
			cin>>x,s.insert(x);
	}
	cout<<n-s.size()<<endl;
	return 0;
}
