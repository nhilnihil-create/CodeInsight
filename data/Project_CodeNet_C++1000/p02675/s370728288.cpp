#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int k = n%10;
	if (k == 2 || k == 4 || k == 5 || k == 7 || k == 9){
		cout<<"hon";
	}
	else if (k == 0 || k == 1 || k == 6 || k == 8){
		cout<<"pon";
	}
	else{
		cout<<"bon";
	}
}