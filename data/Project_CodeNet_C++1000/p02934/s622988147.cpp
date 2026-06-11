#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  double sum=0;
  for(int i=0;i<N;i++){
    double tmp;
    cin>>tmp;
    sum+=1/tmp;
  }
  cout<<fixed<<setprecision(10)<<1/sum<<endl;
}