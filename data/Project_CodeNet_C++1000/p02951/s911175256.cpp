#include<bits/stdc++.h>
using namespace std;

int main(){
	int a,b,c;
	cin>>a>>b>>c;
	int left=c-(a-b);
	if(left<0){
		left=0;
	}
	cout<<left;
	return 0;
	
}