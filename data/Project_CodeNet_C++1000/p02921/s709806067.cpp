#include <iostream>
#include <string>
using namespace std;
 
int main() {
	string s,t;
	int counter=0;
	cin>>s>>t;
	if(s[0]==t[0]){
		counter++;
	}
	if(s[1]==t[1]){
		counter++;
	}
	if(s[2]==t[2]){
		counter++;
	}
	cout<<counter;
}