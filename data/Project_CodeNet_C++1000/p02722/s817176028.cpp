#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <deque>
#include <utility>

bool can1(long long n, long long k){
  if (n%k==0) return false;
  if ((n-1)%k==0) return true;
  else return false;
}

int main(){
  long long N;
  scanf("%lld", &N);
  std::map<long long, int > mp1;
  long long temp = N-1;
  long long ans1=0;
  for (long long i=1; i*i<=temp; i++){
    if (temp%i==0){
      if (i>1) ans1++;
      if (i*i!=temp){
	ans1++;
      }
    }
  }
  
  
  long long ans2 = 0;
  for (long long i=1; i*i<=N; i++){
    temp = N;
    if (temp%i==0){
      if (i>1){
	while(temp%i==0){
	  temp = temp/i;
	}
	if (temp>0 && (temp-1)%i==0) ans2++;
      }
      //
      if (i*i!=N){
	long long opposite = N/i;
	temp = N;
	while(temp%opposite==0){
	  temp = temp/opposite;
	}
	if (temp>0 && (temp-1)%opposite==0) ans2++; 
      }
    }
  }
  std::cout << ans1+ans2 << std::endl;
  return 0;
  
}
 