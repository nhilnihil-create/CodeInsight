#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin>>n;
  vector<int>x(n),y(n),num(n);
  for(int i=0;i<n;i++){
    cin>>x[i]>>y[i];
    num[i]=i;
  }
  double kyori=0;
  int count=1;
  do{
    for(int i=0;i<n-1;i++){
      kyori+=sqrt((x[num[i+1]]-x[num[i]])*(x[num[i+1]]-x[num[i]])+(y[num[i+1]]-y[num[i]])*(y[num[i+1]]-y[num[i]]));
    }
  }while(next_permutation(num.begin(),num.end()));
  for(int i=n;i>=1;--i){
    count*=i;
  }
  double kotae=kyori/(double)count;
  cout<<fixed<<setprecision(12)<<kotae<<endl;
  return 0;
}