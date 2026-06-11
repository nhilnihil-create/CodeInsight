#include<iostream>
#include<algorithm>
using namespace std;
int data[101];
int mod[101];
void ini(void){
  for(int i=0;i<101;i++){
    data[i]=0;
    mod[i]=0;
  }
}



main(){
  int max=0;
  int j;
  j=0;
  int in;
  while(cin >> in){
    for(int i=0;i<101;i++){
      if(in == i){
	data[i]++;//inidata[i];
	break;
      }
    }
    j++;
  }

  //
  for(int i=0;i<101;i++){
    if(max < data[i])max=data[i];
  }

  //
  for(int i=0;i<101;i++){
    if(data[i]==max)cout << i << endl;
  }
  
  return 0;
}