#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int a,flag=0;
	cin >> a;
	for(int i = a;i>0;i--){
		if(0<i&&i<10){flag++;}
		else if(99<i&&i<1000){flag++;}
		else if(9999<i&&i<100000){flag++;}
	}
	cout << flag << endl;
}
