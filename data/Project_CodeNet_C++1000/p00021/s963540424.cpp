#include<cstdio>
#include<iostream>
using namespace std;
main(){
  double x1,x2,x3,x4,y1,y2,y3,y4,a1,a2;
  int n,i;
  cin >> n;
  for(i=0;i<n;i++){
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    a1=(y1-y2)/(x1-x2);
    a2=(y3-y4)/(x3-x4);
    if(a1==a2){
      cout << "YES" << endl;
    }
    else {
      cout << "NO" << endl;
    }
  }
}