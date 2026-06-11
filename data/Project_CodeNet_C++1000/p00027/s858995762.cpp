#include<iostream>
#include<string.h>
using namespace std;

main(){
  int m,d;
  int dc,mc;
  string week[7]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
  int month_days[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
  while(cin >> m >> d){
    
    if(m==0 && d == 0)break;
    
    mc=1;
    dc=3;
    while(1){
      
      for(int i=1;i<=month_days[mc];i++,dc++){
	if(m==mc&& d==i)break;
      }
      if(m==mc)break;
      mc++;
    }
    
    cout << week[dc%7]<<endl;
    
    

  }

  return 0;
}