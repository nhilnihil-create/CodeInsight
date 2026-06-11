#include <iostream>
using namespace std;
 
 
int main(){
	int L, R, d, mul=0; 
	cin>>L>>R>>d;
	for(int i = L; i<=R; i++){
		if(i%d==0){mul++;}
	}
	cout<<mul<<endl;

}