#include <bits/stdc++.h>
using namespace std;

int main(void){
   
   int A,B,C; //A:max B:now C
   cin >> A >> B >> C; 
   
   int sa = A - B;
   
   C -= sa;
   if(C < 0) C = 0;
   
   cout << C <<endl;
}