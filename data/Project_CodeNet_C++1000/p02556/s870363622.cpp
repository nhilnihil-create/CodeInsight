#include<iostream>
#include<algorithm>
using namespace std;
long long int x[200000],y[200000],z[200000],w[200000];
int main(){
  int n,i;
  cin>>n;
  for(i=0;i<n;i++){
    cin>>x[i]>>y[i];
    z[i]=x[i]+y[i];
    w[i]=x[i]-y[i];
    }
  sort(z,z+n)
   ;
  sort(w,w+n);
  cout<<max(z[n-1]-z[0],w[n-1]-w[0])<<endl;
  return 0;
  }
