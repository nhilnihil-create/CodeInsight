#include<iostream>
#include<bitset>
using namespace std;
int main(){
	char N ;
	cin >> N ;	
	bitset<8> chane;
	chane = bitset<8>(N);
	if(chane[5]==0){
		cout << "A" ;
	}
	else{
		cout << "a" ;
	}
	return 0;
}