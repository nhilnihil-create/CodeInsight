#include <iostream>
using namespace std;

int main()
{
	int n, x;
	
	cin >> n;
	x = n%10;
	
	if(x==2||x==4||x==5||x==7||x==9){
		cout << "hon";
	}
	else if(x==0||x==1||x==6||x==8){
		cout << "pon";
	}
	else if(x==3){
		cout << "bon";
	}
	
	
return 0;
}