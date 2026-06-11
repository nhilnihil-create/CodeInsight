#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int inner, display;
	cin >> inner >> display;
	if(inner < 10){
		int rat = display + 100 *(10- inner);
		cout << rat;
	}else{
		cout << display;
	}
	return 0;
}