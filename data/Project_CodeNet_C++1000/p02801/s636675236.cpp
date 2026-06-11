#include <iostream>
#include <string>
using namespace std;

int panjang;
string abjad="abcdefghijklmnopqrstuvwxyz", input;

int main (){
	cin>>input;
	for (int i=0; i<=26; i++){
		if (abjad [i] == input [0]){
			cout<<abjad [i+1];
		}
	}
}