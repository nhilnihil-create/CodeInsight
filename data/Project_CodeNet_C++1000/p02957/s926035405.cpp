#include<bits/stdc++.h>
using namespace std;

int main(){
	int x,y;
	cin>>x>>y;
	if(x%2!=y%2){
		cout<<"IMPOSSIBLE";
	}
	else{
		cout<<(x+y)/2;
		
	}
	return 0;
}