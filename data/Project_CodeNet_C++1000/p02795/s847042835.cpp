#include <bits/stdc++.h>
using namespace std;



int main(){
	int H,W,N;
  
  	cin>>H;
  	cin>>W;
  	cin>>N;
  	
  	int sum=0;
  	int count=0;
  	for(int i=1;i<=max(H,W);i++){
      sum+=max(H,W);
      count=i;
      if(sum>=N)
        break;
    }
  
  	cout<<count<<endl;
  
  	return 0;
}

