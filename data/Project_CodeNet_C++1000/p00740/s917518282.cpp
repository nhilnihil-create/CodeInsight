#include <iostream>

using namespace std;

int main(){
  int n,p;
  cin >> n >> p;
  while(1){
    if(n==0)break;
    int have[n]={},i=0,con=0,non=n;
    while(1){
      if(p>0){
        if(have[i]==0)non--;
        have[i]++;
        p--;
        if(p==0 && non==n-1)break;
      }else{
        if(have[i]>0){
          p+=have[i];
          have[i]=0;
          non++;
        }
      }
      i++;
      if(i==n)i=0;
    }
    cout << i << endl;
    cin >> n >> p;
  }
  return 0;
}

