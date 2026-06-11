#include <iostream>
using namespace std;

int banyak, helth[55], maks;

int main (){
	cin>>banyak;
	for (int i=1; i<=banyak; i++){
		cin>>helth[i];
	}
	for (int i=1; i<=banyak; i++){
		for (int j=1; j<=banyak; j++){
			if (i==j){
				
			}
			else{
				maks+=helth[i]*helth[j];
			}
		}
	}
	cout<<maks/2<<endl;
}