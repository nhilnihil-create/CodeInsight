#include<bits/stdc++.h>
using namespace std;

int main(){
  long x[1000],y[1000];
  int n;
  cin>>n;
  cout<<fixed<<setprecision(10);
  for(int i=0; i<n; i++){
    cin>>x[i];
  }

  for(int i=0; i<n; i++){
    cin>>y[i];
  }

  double maxn=0;
  for(int p=1; p<4; p++){
    double sum=0;
    for(int i=0; i<n; i++){
      sum += pow(abs(x[i]-y[i]),p);
      maxn = max((double)abs(x[i]-y[i]),maxn);
    }
    cout<<pow(sum,(double)1/p)<<endl;
  }
  cout<<maxn<<endl;
}


