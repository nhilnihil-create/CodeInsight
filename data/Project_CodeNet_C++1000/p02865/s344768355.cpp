#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
  	cin >> n;
  	int ctr = 0;
  	for(int i=1; i<n; i++){
    	int temp = n-i;
      	if(temp>i && temp!=i)
          	ctr++;
    }
  	cout << ctr;
  	return 0;
}