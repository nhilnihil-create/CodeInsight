#include<iostream>
using namespace std;
int main(){
int X,Y;
  cin>>X>>Y;
  int n,z;
  n=Y-2*X;
  z=4*X-Y;
  if(n%2==0 && n/2>=0 && z%2==0 && z/2>=0){ 
  cout << "Yes"<<endl;}
    else 
    {cout<<"No"<<endl;}
  
    return 0;
    }
 