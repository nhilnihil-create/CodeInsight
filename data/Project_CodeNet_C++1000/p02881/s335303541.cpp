#include<bits/stdc++.h>
using namespace std;

int main(){

	long long n;
	cin >> n;
  
  	if ( n == 2 ){
      cout << 1 << endl;
      return 0;
    }else if ( n == 3 ){
      cout << 2 << endl;
      return 0;
    }

	long long a;

	a = sqrt(n);

	if ( a * a == n ){
		cout << (a-1) + (a-1) << endl;
	}else{
		for ( long long i = a; i >= 1; i--){
			if ( n % i == 0 ){
				cout << (n / i -1) + (i-1) << endl;
                return 0;
			}
		}
	}

	return 0;

}
