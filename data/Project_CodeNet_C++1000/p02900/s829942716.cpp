#include <bits/stdc++.h>
using namespace std;

#define froop1(a,n) for(long long i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)
int main(){
	long long N,M,count= 0;
  cin >> N >> M;
 set<long long> N1;
  set<long long> M1;
  long long sN = N,sM = M;
  
  froop1(2,sqrt(sN) + 1){
    if(N == 1){
      break;
    }else{
      while(N % i == 0){
      N1.insert(i);
        N /= i;
      }
    }
  }
  if(N > sqrt(sN) + 1){
    N1.insert(N);
  }
    froop1(2,sqrt(sM) + 1){
    if(M == 1){
      break;
    }else{
        if(N1.count(i) && M % i == 0){
			count++;
    	}
      while(M % i == 0){
      M1.insert(i);
        M /= i;
      }
    }
  }
    if(M > sqrt(sM) + 1 && N1.count(M)){
    count++;
  }
  
cout << count + 1 << endl;
  
  
return 0;
}