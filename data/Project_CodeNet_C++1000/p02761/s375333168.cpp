#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
  	int req[3]={-1, -1, -1};
	int n,m;
    std::cin >> n >> m;
    for(int i=0;i<m;i++){
    	int pos, val;
        std::cin >> pos >> val;
        if(req[n-pos]==-1){
          	req[n-pos]=val;
        }else if(req[n-pos]!=val){
        	std::cout << "-1\n";
            return 0;
        }
    }
  	if(n==1){
      	if(req[0]==-1) req[0]=0;
    }else{
    for(int i=0;i<(n-1);i++){
        if(req[i]==-1){
			req[i]=0;
        }
    }
  	if(req[n-1]==-1){
		req[n-1]=1;
	}else if(n!=1 && req[n-1]==0){
        std::cout << "-1\n";
    	return 0;
    }
    }
    for(int i=0;i<n;i++){
    	std::cout << req[n-i-1];
    }
  	std::cout << "\n";
  	return 0;
}
