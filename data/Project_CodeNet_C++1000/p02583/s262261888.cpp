#include <iostream>
//#include <string>
#include <algorithm>
using namespace std;
typedef unsigned int u_i;

int main(){

 	int n,count=0;
  	cin >> n;
  	if(n<3){
      cout << count << endl;
      return 0;
    }
  	u_i l[n],mx;
  	for(int i=0; i<n; ++i){
      cin >> l[i];
    }
	for(int i=0; i<n-2; ++i){
      for(int j=i+1; j<n-1; ++j){
        for(int k=j+1; k<n; ++k){
          mx = max({l[i],l[j],l[k]});
          if((mx<l[i]+l[j]+l[k]-mx) && (l[i]!=l[j] && l[i]!=l[k] && l[k]!=l[j]) ){
            count++;
          }
        }
      }
    }
  	
  
  	cout << count << endl;
	return 0;
}