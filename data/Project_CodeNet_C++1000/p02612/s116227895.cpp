#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  int n=N/1000;
  if(N%1000==0) cout<< 0<<endl;
  else cout<< 1000*(n+1)-N <<endl;
}