#include<iostream>
using namespace std;

int main() {
	int n=0; 
  	cin >> n;
  	long long int ans = 0;
  	for(int i=1; i <= n; i++) {
      	if(i % 3 == 0 && i % 5 == 0)
          continue;
    	if(i % 3 == 0 || i % 5 == 0)
          continue;
      	ans = ans + i;
    }
   	cout << ans;
 	return 0;
}