#include <iostream>
#include <string>
using namespace std;

int main() {
    int d = 0 , t = 0 , s = 0;
    cin >> d >> t >> s;
    if(s>= (double)d/t){
		cout << "Yes";
	}else{
		cout << "No";
	}
	return 0;
}
