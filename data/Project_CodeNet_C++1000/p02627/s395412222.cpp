#include <iostream>
#include <string>

using namespace std;

int main(){
	char a;
	while(cin >> a){
		if(isupper(a)){
			cout << 'A' << endl;
		}else {
			cout << 'a' << endl;
		}
	}
}

