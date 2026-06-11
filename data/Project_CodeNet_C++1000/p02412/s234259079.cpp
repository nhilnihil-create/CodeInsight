#include <iostream>
using namespace std;

int main(){
  int n,x,count;

  while(1){
    cin>>n>>x;
    if(n==0 && x==0) break;
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
	for(int k=1;k<=n;k++){
	  if(i+j+k==x && i!=j && i!=k && j!=k && i<j && j<k) count++;
	}
      }
    }
    cout<<count<<endl;
    count=0;
  }
  return 0;
}

