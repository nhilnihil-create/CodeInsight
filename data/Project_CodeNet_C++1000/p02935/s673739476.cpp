#include<bits/stdc++.h>
using namespace std;


int main() {
  cout<<fixed<<setprecision(10);
  int N;cin>>N;
 /* vector<double> v(N);
  for(int i=0;i<N;i++) cin>>v.at(i);*/
  priority_queue<double,vector<double>,greater<double>> v;
  for(int i=0;i<N;i++){
    double X;cin>>X;
    v.push(X);
  }
  while(v.size()>1){
    double y=v.top();
    v.pop();
    double z=v.top();
    v.pop();
    double S=(y+z)/2;
    v.push(S);
  }
  cout<<v.top()<<endl;
}


