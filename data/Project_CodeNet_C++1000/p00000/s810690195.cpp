#include<iostream>
using namespace std;

int main(){
int num[9][9];
for(int n=1; n<=9; n++)
 for(int m =n; m<=9; m++)
  num[n][m]=n*m;

for(int n=1; n<=9; n++)
  for(int m=1; m<=9; m++){
   if(n>m)
    cout << n << "x" << m << "=" << num[m][n] <<endl; 
   else
    cout << n << "x" << m << "=" <<num[n][m] <<endl; 
  }
    return 0;
}