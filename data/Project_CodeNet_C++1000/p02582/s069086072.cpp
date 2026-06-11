#include<iostream>
using namespace std;

int main() {
  string S;
  cin>>S;
  int C=0;
  if (S=="RRR") C=3;
  else if(S=="RRS") C=2;
  else if(S=="RSR") C=1;
  else if(S=="RSS") C=1;
  else if(S=="SRR") C=2;
  else if(S=="SRS") C=1;
  else if(S=="SSR") C=1;
  else if(S=="SSS") C=0;
  cout<<C<<endl;
  return 0;
}
