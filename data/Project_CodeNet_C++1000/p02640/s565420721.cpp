#include<iostream>
using namespace std;
int Tru(int x,int y){
  int c=0;

  while(c!=x+1){
    if(2*c+4*(x-c)==y){
      return 2;
    }
	c++;
 }
 return 1;
}
int main(){
	int x,y;
	cin>>x>>y;
  if(Tru(x,y)==2)
    cout<<"Yes";
  else
    cout<<"No";
  return 0;
}
 