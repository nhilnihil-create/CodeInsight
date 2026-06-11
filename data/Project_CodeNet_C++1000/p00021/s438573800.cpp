#include<iostream>
using namespace std;




main(){

  
  int n;
  
  cin  >> n;
  double x1,y1,x2,y2,x3,y3,x4,y4;

  for(int i=0;i<n;i++)
    {
  
      cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

      double hoge=(x1-x2)*(y3-y4);//,

      double hoge2=(x3-x4)*(y1-y2);

      if(hoge == hoge2)cout << "YES"<<endl;
      else cout << "NO"<< endl;
      
      
  
    }
  
  return 0;
}