#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  double total;
  vector<double> a(N);
  //vector<double> b(N);
  cin>>N;
  for(int i=0;i<N;i++){
    cin>>a[i];
    total+=1/a[i];
  }
  cout<<1/total<<endl;
}
  