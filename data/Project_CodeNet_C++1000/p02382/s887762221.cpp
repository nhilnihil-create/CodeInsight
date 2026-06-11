#include<bits/stdc++.h>
using namespace std;
int main(){
  cout<<fixed<<setprecision(12);
  int n,dinf=0;
  int x[1000];
  int y[1000];
  int dif[1000];
  double sum=0,d2=0,d3=0;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>x[i];
  }
  for(int i=0;i<n;i++){
    cin>>y[i];
  }
  for(int i=0;i<n;i++){
    dif[i]=abs(x[i]-y[i]);
    sum+=dif[i];
  }
  cout<<sum<<endl;
  for(int i=0;i<n;i++){
    d2+=pow(dif[i],2);
    d3+=pow(dif[i],3);
    dinf=max(dinf,abs(x[i]-y[i]) );
  }
  cout<<sqrt(d2)<<endl<<pow(d3,(double)1.0/(double)3)<<endl<<dinf<<endl;
  return 0;
}

