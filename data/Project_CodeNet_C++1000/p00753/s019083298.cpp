#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n;
	while(cin>>n, n!=0){
		int count=0;
		int i = n+1;
		if(n!=1){
			if(i%2==0) i++;
			while(i<=(2*n)){
				int t=0;
				for(int j=3 ; j <= sqrt(i) ; j+=2){
					if(i%j==0){
						t=1;
						break;
					}
				}
				if(t==0) count++;
				i+=2;
			}
		}
		else count++;
		cout << count << endl;
	}
	return 0;
}