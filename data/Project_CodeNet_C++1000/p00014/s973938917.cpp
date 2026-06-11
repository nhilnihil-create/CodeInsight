#include <iostream>
using namespace std;

int f(int x){
	return (x*x);
}

int main(){
	int d,s;

	while( cin >> d ){
		s = 0;
		for(int i=1 ; (d*i)<=(600-d) ; i++){
			s += f(d*i)*d;
		}
		cout << s << endl;
	}
}