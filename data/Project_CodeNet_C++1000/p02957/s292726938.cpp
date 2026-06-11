#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int a,b;
	cin >> a >> b;
	int c=abs(b+a);
	
	if(c%2==0){
		cout << c/2 << endl;
	}
	else{
		cout << "IMPOSSIBLE" << endl;
	}
	
	return 0;
}