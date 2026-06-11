#include <iostream>

using namespace std;
int main()
{
	while(true){
		int n; 
		cin >> n ;
		if(n == 0 ) break;
			int sum;
			int ans =0;
			for (int i = 1; i<n; i++){
				sum = 0;
	   			for (int j = i; j<n; j++){
	   				sum = sum + j;
	   				if(sum == n)
	   					ans = ans +1;
	   			}
	   		}
		cout << ans<<endl;
	}
}