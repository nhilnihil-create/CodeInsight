#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int main(){
  int N,X,Y;
  cin>>N>>X>>Y;
  int answer[2000];
  for(int i=0;i<N;i++) answer[i]=0;
  for(int i=1;i<N;i++){
    for(int j=i+1;j<=N;j++){
      if(i<X){
        if(j<=X) answer[j-i]++;
        else if(j<=Y){
          int k=min(j-i,X+Y-i-j+1);
          answer[k]++;
        }
        else answer[X-Y-i+j+1]++;
      }
      else if(i<=Y){
        if(j<=Y){
          int k=min(j-i,i-X+Y-j+1);
          answer[k]++;
        }
        else{
          int k=min(j-i,i+j-X-Y+1);
          answer[k]++;
        }
      }
      else answer[j-i]++;
    }
  }
  for(int i=1;i<N;i++) cout<<answer[i]<<endl;
  
  return 0;
}