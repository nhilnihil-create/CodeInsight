#include <iostream>
#include<string>
#include<math.h>
#include<stdio.h>
#include <algorithm>
using namespace std;
int main(void){
    // Here your code !
int a[9],b[9];
int c;

for(int i=0;i<9;i++){
 a[i]=i+1;   
 b[i]=i+1;
}
for(int i=0;i<9;i++){
  for(int j=0;j<9;j++){
  cout<<a[i]<<'x'<<b[j]<<'='<<a[i]*b[j]<<endl;    
}
}
return 0;
}