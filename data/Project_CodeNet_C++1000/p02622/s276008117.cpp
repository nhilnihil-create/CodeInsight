#include <iostream>
#include <string>
using namespace std;

int main() {
	string A, B;
  	cin >> A >> B;
  
  	int count = 0;
  	for (int i = 0; i < (int)A.length(); ++i) {
    	if (A[i] != B[i]) ++count;
    }
  
  	printf("%d\n", count);
}