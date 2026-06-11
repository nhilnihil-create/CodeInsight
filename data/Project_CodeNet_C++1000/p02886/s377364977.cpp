#include <iostream>
#include<vector>
#include<cmath>
#define ll long long
using namespace std;
#define rep2(i,a,n) for(int i=a;i<=n;i++)
int main(void){
    // Your code here!
  int n;
  cin>>n;
  vector<int> vec(n,0);
  
  for(int i=0;i<n;i++){
      cin>>vec[i];
  }
  
  
 ll sum=0;
  for(int i=0;i<n-1;i++){
      for(int j=i+1;j<n;j++){
          sum+=vec[i]*vec[j];
      }
  }
  cout<<sum;
}
