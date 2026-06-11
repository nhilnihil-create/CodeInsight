#include <iostream>
#include <string>
using namespace std;

int panjang;
string s;
string t;

int main(){
	cin>>s>>t;
	panjang=s.length();
	s+=t[panjang];
	if(s==t){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
}
