#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

void comb(int N, int X){
	int com = 0;
	
	for(int i=1; i<=N-2; i++){
		for(int j=i+1; j<=N-1; j++){
			for(int k=j+1; k<=N; k++){
				if(i+j+k == X) com += 1;
			}
		}
	}
	
	cout << com << endl;
}

int main(){
	int n, x;
	
	while(true){
		cin >> n >> x;
		if(n==0 && x==0) break;
		
		comb(n, x);
	}
}