#include <iostream>
using namespace std;
int main(){
	int d;
	while(cin>>d){
		long s=0;
		int a = 600/d;
		for(int i=0;i<a;i++){
			s += i*d*i*d*d;
		}
		cout<<s<<endl;
	}
	return 0;
}