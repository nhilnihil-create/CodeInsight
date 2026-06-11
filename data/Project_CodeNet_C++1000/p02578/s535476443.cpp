#include <iostream>
using namespace std;
typedef unsigned long long u_i;

int main(){

  	int n;
  	cin >> n;
	u_i sum=0,tmp,ptmp;
  	cin >> ptmp;
  	for(int i=1; i<n; ++i){
      cin >> tmp;
      if(ptmp>tmp){
        u_i ttmp = ptmp-tmp;
      	sum += ttmp;
        tmp += ttmp;
      }
      ptmp = tmp;
    }
  
    cout << sum << endl;  
	return 0;
}