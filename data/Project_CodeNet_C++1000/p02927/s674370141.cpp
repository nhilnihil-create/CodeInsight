#include<iostream>
using namespace std ;

int main()
{
  int M,D ;
  cin>>M>>D ;
  
  /*m月d日:d=10*e+f
    e>=2 && f>=2 && e*f==m */
  int count=0 ;
  for(int e=2;e<=D/10;e++){
    for(int f=2;e*10+f<=D&&f<=9;f++){
      if(e*f<=M) count++ ;
    }
  }
  cout<<count<<endl ;
  
  return 0 ;
}
