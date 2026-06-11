#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
using namespace std;
int main(){
  int N;
  cin>>N;
  string s;
  cin>>s;
  int answer=0;
  for(int i=0;i<1000;i++){
    int x[3]={i/100,(i%100)/10,i%10};
    int judge=0;
    int j=0;
    while(j<N&&judge<3){
      if(s[j]-'0'==x[judge]) judge++;
      j++;
    }
    if(judge==3) answer++;
  }
  cout<<answer<<endl;
  
  return 0;
}