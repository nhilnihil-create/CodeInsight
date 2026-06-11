#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

//#define rep(i,0,n) for(int i=0; i<n; i++)

using namespace std;

bool fact(int n){
	int k = sqrt(n);
	if(n % 2 ==0) return false;
	else{
		for(int i = 3; i <= k; i = i+2){
			if(n % i == 0) return false;
		}
		return true;
	}
	return 0;
}

void factorize(int n){
	vector<int> fac;
	cout << n <<": ";
	if(fact(n) == true){
		cout << n << endl;
		return;
	}
	while(n % 2 ==0){
		n /= 2;
		fac.push_back(2);
	}

	if(n !=1){
		/*
		//int k = sqrt(n);
		for(int i=3; i<=n/2; i = i+2){
			if(n % i == 0){
				n /= i;
				//cout << i << " ";
				fac.push_back(i);
				i -= 2;
			}
		}*/
		int i=3;
		while(n>1){
			if(n % i == 0){n /= i; fac.push_back(i);}
			else {i = i+2;}
		}
	}

	//cout << endl;
	int m = fac.size();
	for(int i=0; i<m-1; i++){
		cout << fac[i] << " ";
	}
	cout << fac[m-1] << endl;
}
int main(){
	int n;
	cin >> n;
	factorize(n);
	//cout << fact(n) << endl;

	return 0;
}