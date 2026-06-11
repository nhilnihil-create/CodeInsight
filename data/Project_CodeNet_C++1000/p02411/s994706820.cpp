#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
  
  int m,f,r;


  while(1){
    cin >> m >> f >> r;

    if(m==-1 && f==-1 && r==-1){
      break;
    }else{
      int mark=0;
      char grade=0;
      
      if(m==-1 || f==-1 ){
        grade = 'F';
      }

      if(m!=-1){
        mark += m;
      }
      if(f!=-1){
        mark += f;
      }

      if(grade == 0){
        if(mark >= 80){
          grade = 'A';
        }else if(mark >= 65){
          grade = 'B';
        }else if(mark >= 50){
          grade = 'C';
        }else if(mark >=30){
          if(r >= 50){
            grade = 'C';
          }else{
            grade = 'D';
          }
        }else{
          grade = 'F';
        }
      }
    
      cout << grade << endl;
    }
  }
}