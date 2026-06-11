#include<iostream>
using namespace std;
int main(){
	int a,b;
	cin>>a>>b;
	int totl = 2*b;
	int ans = a - totl;
	if(ans<1){
		cout<<0<<endl;
	} else{
		cout<<ans<<endl;
	}

}