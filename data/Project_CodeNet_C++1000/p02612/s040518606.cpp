#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,tienle;
	cin>> n;
	if (n%1000==0){tienle=0;
	}
	else tienle=1000-(n%1000) ;
	cout<< tienle << endl ;
	
	return 0;
}
