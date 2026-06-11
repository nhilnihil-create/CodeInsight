#include <iostream>
using namespace std;

int main(){
	int n,x,t;
	cin>>n>>x>>t;
	int tmp=n/x;
	if(n%x==0){
		cout<<tmp*t<<endl;
	}
	else{
		cout << (tmp+1)*t << endl;
	}
	return 0;
}