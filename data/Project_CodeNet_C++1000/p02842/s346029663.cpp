#include<bits/stdc++.h>
using namespace std;
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n;
	cin>>n;
	long long x;
	x=ceil(n/1.08);
	if(floor(x*1.08)==n){
		cout<<x<<"\n";
	}else{
		cout<<":("<<"\n";
	}
	
	

	



	


 
	
	
	
	
	return 0;
}