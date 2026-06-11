#include <iostream>
using namespace std;
int main(){
	int sm,gj;
	cin>>sm>>gj;
	if(sm%gj==0) cout<<sm/gj;
	else cout<<sm/gj+1;
	return 0;
}