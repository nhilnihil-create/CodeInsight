#include<iostream>
using namespace std;

int main(){
int h,w,i,j;
i=1;
j=1;
while(true){
 cin >> h>>w;
 if (h==0 && w==0) break;
 while(j<=h){
  while(i<=w){
  cout <<"#";
  i++; 
  }
  cout << endl;
  i=1;
 j++;
 }
cout << endl;
j=1;
} 
   return 0;
}