#include <iostream>
using namespace std;

int main() {
	int x;
	cin >> x;
	int A[x];
	for (int i=0; i<x; i++) cin >> A[i];
	int sum=0;
	for (int i=0; i<x-1; i++){
	    for (int j=i+1; j<x; j++){
	        sum+=A[i]*A[j];
	    }
	}
	cout << sum << endl;
}
