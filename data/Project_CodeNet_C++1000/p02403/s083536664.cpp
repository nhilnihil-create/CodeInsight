#include<iostream>
using namespace std;
int main(){
  int a,b;
  char map[300][300];
  while(1){
    cin>>a>>b;
    if(a==0&&b==0){
      break;
    }
    for(int i=0;i<a;i++){
      for(int j=0;j<b;j++){
	map[j][i]='#';
	cout<<map[j][i];
      }
      cout<<endl;
    }
    cout<<endl;
  }
  return(0);
}