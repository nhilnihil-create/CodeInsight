#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	if(n%1000 == 0){
	cout << "0" << endl;
	}
	else{
	int diff = 1000 - (n%1000);
	cout << diff << endl;
	}
return 0;
}
