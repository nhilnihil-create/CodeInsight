#include<bits/stdc++.h>
using namespace std;

int main(){
	int x, y, z, i, v1, v2, a, b, j, max;
	
	while(1){
		max = 0;
		cin>>x>>y>>z;
		
		a = ( z * 100 ) / (100 + x);
		
		b = z - a;
		
		if(x == 0 && y == 0 && z == 0) break;
		
		for(i = 1; i < z; i++){
			for(j = b; i < a + j; j--){
				if((i * (100 + x) / 100 + (a - i + j) * (100 + x) / 100) == z){
					if((i * (100 + y) / 100 + (a - i + j) * (100 + y) / 100) > max){
						max = (i * (100 + y) / 100) + ((a - i + j) * (100 + y) / 100);
					}
				}
			}
		}
		
		cout<<max<<endl;
	}
	
	return 0;
}
