#include<bits/stdc++.h>

using namespace std;

int main(){
 	int h1,h2,m1,m2,k;
 	cin>>h1>>m1>>h2>>m2>>k;
  	int minutes;
  	if(m1>m2){
     	minutes = m2+60-m1;
      	minutes += (h2-1-h1)*60;
    }else{
      minutes = m2-m1;
      minutes += (h2-h1)*60;
    }
  cout<<minutes-k<<endl;
  return 0;
  
}
