#include <iostream>
#include <cmath>
#include <stdint.h>
#include <iomanip>
#include <vector>
#include<algorithm>
#include <queue>
using namespace std;
 
#define int long long
#define INF 1001001001

int arr[200001];
 
int nChoosek( int n, int k )
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    int result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}

int choose2(int n){
	
	return n*(n-1)/2;
}


int num[3];

int32_t main() {
	
   int N,M;
   
   cin >> N>>M; 
   num[0] = num[1] = num[2] = -1;

   for(int i=0; i<M; i++){
   	
   		int s,c;
   		
   		cin >> s >> c;  		
   		
   	 	if(num[s-1] != -1 && num[s-1] != c){
   	 		cout << "-1" << endl;
   	 		return 0;
		}			
   	
   		num[s-1] = c;
   }
   
   if(num[0] == 0 && N>1){
   		cout << "-1" << endl;
   }
   else{
   		if(N==1 && num[0]==-1){
   			cout << 0 << endl;
		   }
   		else{
		   
   		
	   		for(int i =0; i<N;i++){
	   			
	   			if(num[i] ==-1 && i==0){
	   				cout << 1;
				}
	   			else{
	   				if(num[i] == -1)
	   					cout << 0 ;
	   				else
	   					cout << num[i];
				}	
	   			
			}
  		 }
   }
}