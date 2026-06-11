#include <iostream>
#include <string>

using namespace std;

long long int kaijo(int a){
	if(a==0){
		return 1;
	}
	else {
		return a*kaijo(a-1);
	}
	
}

int main(){
	int n;
	cin>>n;
	cout<<kaijo(n)<<endl;
	return 0;
}