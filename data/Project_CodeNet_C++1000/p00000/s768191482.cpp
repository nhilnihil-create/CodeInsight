#include <bits/stdc++.h>
using namespace std;

int i=1,j;
int main(){
	if(++j==10){
		if(++i==10) return 0;
		j=1;
	}
	cout<<i<<"x"<<j<<"="<<i*j<<endl;
	main();
}