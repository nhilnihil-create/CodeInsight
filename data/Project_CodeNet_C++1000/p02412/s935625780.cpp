
#include <iostream>
using namespace std;


int main(){
	
	while(1){
		
		int n,x,ans = 0;
		cin >> n >> x;
		
		if(n == 0 && x == 0)	break;
		for(int i = 1;i <= n-2;i++){
			for(int j = i+1;j <= n-1;j++){
				int A = x - (i + j);
				if(A > n || A <= j)	continue;
				else{
					ans++;
				}
			}
		}
		
		cout << ans << endl;
		
	}
	
	return 0;
}