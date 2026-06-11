#include <iostream>
#define L 250000
using namespace std;
int main(){
  int n,i,j,sosu[L],cnt;
  for(i=0;i<L;i++)sosu[i]=1;
  sosu[0]=0;
  sosu[1]=0;
  for(i=0;i<L/2;i++){
    if(sosu[i]==1){
      for(j=i*2;j<L;j+=i){
        sosu[j]=0;
      }
    }
  }
   while(1){
    cin >> n;
    if(n==0) break;
    cnt=0;
    for(i=n+1;i<=2*n;i++){
      if(sosu[i]==1) cnt++;
    }
    cout << cnt << endl;
  }
  return 0;
}