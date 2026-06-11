#include <iostream>
using namespace std;

int main(){
  int m,mini,maxi;
  while(1){
    cin>>m>>mini>>maxi;
    if(m==0&&mini==0&&maxi==0)break;
    int p[205];
    for(int i=0;i<m;i++)cin>>p[i];
    int gap=-1,t;
    if(m==maxi)maxi--;
    for(int i=mini-1;i<maxi;i++){
      //cout<<i+1<<": "<<p[i]-p[i+1]<<endl;
      if(gap<=p[i]-p[i+1]){
	gap=p[i]-p[i+1];
	t=i+1;
      }
    }
    cout<<t<<endl;
  }
  
  return 0;
}