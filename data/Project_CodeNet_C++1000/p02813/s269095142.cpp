#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin>>n;
  vector<int>num(n),p(n),q(n);
  for(int i=0;i<n;i++)num[i]=i;
  for(int i=0;i<n;i++)cin>>p[i];
  for(int i=0;i<n;i++)cin>>q[i];
  int start=0;
  int last=0;
  int count=0;
  do{
    int counts=0;
    int countl=0;
      for(int i=0;i<n;i++){
        //cout<<num[i]+1<<p[i]<<q[i]<<endl;
        if(num[i]+1==p[i])counts++;
        if(num[i]+1==q[i])countl++;
      }
      count++;
      //cout<<counts<<" "<<countl<<" "<<count<<endl;
      if(counts==n)start=count;
      if(countl==n)last=count;
  }while(next_permutation(num.begin(),num.end()));
  cout<<abs(start-last)<<endl;
  return 0;
}
  

  
