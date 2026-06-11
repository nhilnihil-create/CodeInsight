#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,d1,d2,i,c=0,ans=0;
  	cin >> n;
  	for(i=0;i<n;i++){
     	cin >> d1 >> d2;
      	if(d1==d2) {
          c++;
        } else {
          c = 0; 
        }
      	if(c==3) {
         ans = 1; 
        }
    }
  	if(ans==1) {
     	cout << "Yes" << endl; 
    } else {
     	cout << "No" << endl; 
    }
}
