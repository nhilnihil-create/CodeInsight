#include <bits/stdc++.h>
using namespace std;

int main(){
  int M,D,i=0;
  cin>>M>>D;
  for(int m=4;m<=M;m++)
    for(int d10=2;d10*10<=D;d10++)
      for(int d1=2;d10*10+d1<=D && d1<10;d1++)
        if(m==d1*d10)
          i++;
  cout<<i<<endl;
}