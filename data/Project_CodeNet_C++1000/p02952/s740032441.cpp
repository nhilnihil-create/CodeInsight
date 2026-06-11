#include<iostream>
#include<algorithm>
#include<vector>
#include <iomanip>
#include <cmath>
#include <string.h>
#include <stdio.h>

using namespace std;

int findDigits(int n){
	int cnt=0;
  	while(n>0){
    	n= n/10;
      	cnt++;
    }
  
  return cnt;
}

int main(){

  int N;
  
  cin >> N;
  
  int cnt=0;
  for(int i=1; i<=N; i++){
	int answer = findDigits(i);
    if(answer%2 !=0)
      cnt++;
  }
 
  cout << cnt << endl;
  

  
  return 0;
  
}
