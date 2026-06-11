#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
  int n;
  vector<int> result;

  while(cin>>n,n!=0){
    int count=0;
    int i=n+1;
    if(n!=1){
      if(i%2==0) i++;
      while(i<=2*n){
	int k=0;
	for(int j=3;j<=sqrt(i);j+=2){
	  if(i%j==0){
	    k=1;
	    break;
	  }
	}
	if(k==0) count++;
	i+=2;
      }
    }
    else count++;
    
    result.push_back(count);
  }
  
  for(auto i:result){
    cout<<i<<endl;
  }
}