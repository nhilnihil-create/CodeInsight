#include<iostream>
#include<string>
using namespace std;

string shuffle(string a, int b){

	string s1= a, s2;
	int c1 = b;

	s2=s1.substr( 0, c1 );
	s1=s1.erase( 0, c1 );
	s1+=s2;

	return s1;
}

int main(){
	string str;
	int ct, ct2;

while(1){
	cin >> str;
	if(str=="-"){break;}
	cin >> ct;
	for(int i=0; i<ct; i++){ cin >> ct2; str=shuffle(str ,ct2);}	
	cout << str <<endl;
}

return 0;
}