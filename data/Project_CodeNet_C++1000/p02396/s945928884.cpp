#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int i;
	int a;
	for(i=1;;i++){
		cin >>a;
		if(a==0)break;
		cout <<"Case " <<i <<": " <<a <<'\n';
	}
	return 0;
}