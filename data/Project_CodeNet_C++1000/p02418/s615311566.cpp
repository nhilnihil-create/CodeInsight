#include <iostream>
using namespace std;
main(){
	string s,p;
	cin>>s>>p;
	cout<<((s+s).find(p)!=string::npos?"Yes\n":"No\n");
}