#include <bits/stdc++.h>
using namespace std;

int main(){
  long long A,B,C,D;
  cin>>A>>B>>C>>D;
  long long E=lcm(C,D);
  //cout<<B-A+1<<endl;
  //cout<<B/C-(A-1)/C<<endl;
  //cout<<B/D-(A-1)/D<<endl;
  //cout<<B/E-(A-1)/E<<endl;
  cout<<B-A+1-(B/C-(A-1)/C)-(B/D-(A-1)/D)+B/E-(A-1)/E<<endl; 
  return 0;
}

