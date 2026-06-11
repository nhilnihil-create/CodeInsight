#include <iostream>
using namespace std;

int main(){
	string p, s;
	cin >> p >> s;
	p += p;
	
	string::size_type index = p.find(s);
	if(index != string::npos){
		cout << "Yes" << endl;
	}
	else{
		cout << "No" << endl;
	}
	
	return 0;
}