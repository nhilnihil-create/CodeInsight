#include<iostream>
#include<vector>
using namespace std;
int main(){
  int n,k;
  cin>>n>>k;
  vector<int>a(n,0);
  int d,val;
  for(int i=0;i<k;i++){
    cin>>d;
    for(int j=0;j<d;j++){
      cin>>val;
      a[val-1]+=1;
    }
  }
  int sum = 0;
  for(int i=0;i<n;i++){
    if(a[i]==0)sum++;
  }
  cout<<sum<<endl;
  
  return 0;
}