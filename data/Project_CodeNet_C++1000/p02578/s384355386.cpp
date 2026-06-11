#include <iostream>
#include <vector>

using namespace std;

int main(){
	long long n;
  	long long max_a = 0;
  	long long tot = 0;
  	cin >> n;
  	for (int i=0;i<n;i++) {
    	long long a;
      	cin >> a;
      	if (max_a > a) {
			tot += max_a - a;
        } else {
        	max_a = a;
        }
    }
  cout << tot << endl;
  return(0);
}