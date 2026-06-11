#include <iostream>
#include <cmath>
#define MAX 1000000
using namespace std;

void eratos(int,bool*);

main(){
  bool prime[MAX+1];
  eratos(MAX, prime);

  while(1){
    int a, d, n;
    cin >> a >> d >> n;
    if(a==0 && d==0 && n==0) break;
    int count=0;
    for(int i=a;i<=MAX;i+=d){
      if(prime[i]){
	count++;
      }
      if(n==count){
	cout << i << endl;
	break;
      }
    }
  }
  return 0;
}

void eratos(int n, bool prime[]){
  for(int i=0;i<=n;i++) prime[i]=false;
  for(int i=3;i<=n;i+=2) prime[i]=true;
  prime[2]=true;
  int limit=(int)sqrt((double)n)+1;
  for(int i=3;i<=limit;i+=2){
    if(!prime[i]) continue;
    for(int j=i+i;j<=n;j+=i) prime[j]=false;
  }
}