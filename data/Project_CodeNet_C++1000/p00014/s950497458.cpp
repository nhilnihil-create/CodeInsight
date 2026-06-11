#include<iostream>
using namespace std;
int main(){
	int d, s;
	while (cin>>d){
		s = 0;
		for (int j = 1; j*d < 600; j++){
			s = s + d*d*d*j*j;
		}
		cout << s << endl;
	}
	return 0;
}