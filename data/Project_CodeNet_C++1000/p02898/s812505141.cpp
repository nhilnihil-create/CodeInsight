#include <iostream>
 using namespace std;
 int main(){
 int a,b;
 cin>>a>>b;

 int c=0;
 for(int i=0;i<a;i++){
 int h;
 cin>>h;
 if(h>=b) c++;
 }

 cout<<c<<endl;
 return 0;
 }