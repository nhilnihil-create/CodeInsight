#include<iostream>
using namespace std;
int main(){
	int n;
	while(cin >> n){
		if(n==0) break;
		int A=0, B=0, a,b;
		for(int i=0; i<n; i++){
			cin >> a >> b;
			if(a>b) A+=a+b;
			if(a<b) B+=a+b;
			if(a==b) A+=a, B+=b;
		}
		cout << A << " " << B << endl;
	}
	return 0;
}