#include<iostream>
using namespace std;
main(){
  int x,y,s;
  int max;
  int t1,t2;
  while(cin >> x >> y >> s,x || y || s){
    x+=100;
    y+=100;
    max=-1;
    for(int s1=1;s1<s;s1++){
      for(int s2=1;s2<s;s2++){
	if((int)s1*x/100+(int)s2*x/100==s){
	  t1=s1*y/100;
	  t2=s2*y/100;
	  if(t1+t2>max || max==-1) max=t1+t2;
	}
      }
    }
    cout << max << endl;
  }
}