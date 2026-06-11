#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>

using namespace std;

int main(){
	
	int m,d;
	int count=0;
	cin >> m >> d;
	
	for(int i=1;i<=m;i++){
		for(int j=2;j<=d;j++){
			for(int k=2;k<10;k++){
				if(10*j+k>d)continue;
				if(j*k==i)count++;
			}
		}
	}
	
	cout << count << endl;
	
	return 0;
}
