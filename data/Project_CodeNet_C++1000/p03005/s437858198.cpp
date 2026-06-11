#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>

using namespace std;

int main(){
	
	int n,k;
	cin >> n >> k;
	
	if(n<k){
		cout << "1" << endl;
		return 0;
	}else if(n==k){
		cout << "0" << endl;
		return 0;
	}else if(n>k){
		if(k==1){
			cout << "0" << endl;
			return 0;
		}else{
			int max=(n-(k-1))-1;
			cout << max << endl;
			return 0;
		}
	}
	return 0;
}
