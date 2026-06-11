#include<bits/stdc++.h>
using namespace std;
int main(void){
  int M[2],D[2];
  for(int i=0;i<2;i++){
    cin>>M[i]>>D[i];
  }
  cout<<(D[0]>D[1]?"1":"0")<<endl;
  return 0;
}
