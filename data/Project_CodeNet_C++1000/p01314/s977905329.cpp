/*** ??£?¶?????????£??°?????? ***/

#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	int count, sum, i, j;
	
	cin >> N;
	while(N!=0){
		count=0;
		for(i=1; i<N/2+1; ++i){
			sum=i;
			for(j=i+1; j<=N/2+1; ++j){
				sum+=j;
				if(sum==N){
					++count;
					break;
				}
				if(sum>N) break;
			}
		}
		cout << count << endl;
		
		cin >> N;
	}
	
	return 0;
}

//500
//124 125 126 127